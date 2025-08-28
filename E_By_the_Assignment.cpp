// coded by Cocane

#include<bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n-1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define allp(x) (x).begin(), (x).begin() + (x).size()/2, (x).rbegin()
#define pb push_back
#define ppb pop_back
#define read(a) for(auto &i: a) cin >> i
#define out(ans) cout<<ans<<endl
#define yn(a) cout<< (a ? "YES": "NO") <<endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

const int MOD = 998244353;

struct DSU {
    vi p, r;
    DSU() {}
    DSU(int n): p(n), r(n,0) { iota(all(p), 0); }
    int f(int x){ return p[x]==x?x:p[x]=f(p[x]); }
    void u_(int a,int b){
        a=f(a); b=f(b);
        if(a==b) return;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
    }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin>>T;
  while(T--){
    int n, m;
    long long V;
    cin >> n >> m >> V;
    vi a(n+1);
    for1(i,n) cin >> a[i];

    vector<vi> g(n+1);
    forn(i,m){
        int u,v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    // Tarjan BCC with edge stack
    vi tin(n+1,0), low(n+1,0);
    int timer = 0;
    vector<pair<int,int>> estk;
    vector<vector<pair<int,int>>> compEdges; // edges for each BCC
    vector<vector<int>> compVerts;           // vertex list for each BCC

    function<void(int,int)> dfs = [&](int u, int p){
        tin[u]=low[u]=++timer;
        for(int v: g[u]){
            if(v==p) continue;
            if(!tin[v]){
                estk.pb({u,v});
                dfs(v,u);
                low[u]=min(low[u], low[v]);
                if(low[v] >= tin[u]){
                    // pop component
                    vector<pair<int,int>> edges;
                    set<int> verts;
                    while(true){
                        auto e = estk.back(); estk.pop_back();
                        edges.pb(e);
                        verts.insert(e.fi); verts.insert(e.se);
                        if(e.fi==u && e.se==v) break;
                    }
                    compEdges.pb(edges);
                    compVerts.emplace_back(verts.begin(), verts.end());
                }
            }else if(tin[v] < tin[u]){ // back edge to ancestor, push once
                estk.pb({u,v});
                low[u]=min(low[u], tin[v]);
            }
        }
    };

    dfs(1, -1); // connected by statement

    int C = (int)compEdges.size();
    // mark which components are cyclic and their bipartiteness
    vector<char> isCyclic(C, 0);
    vector<char> isOdd(C, 0); // true if non-bipartite (has odd cycle)
    vector<vector<int>> compsOf(n+1); // for each vertex, list of cyclic component ids containing it

    for(int cid=0; cid<C; ++cid){
        int E = (int)compEdges[cid].size();
        int Vc = (int)compVerts[cid].size();
        if(E < Vc){
            // no cycle -> no constraints, skip
            continue;
        }
        isCyclic[cid]=1;

        // Build induced graph of this component
        vector<int> verts = compVerts[cid];
        int k = (int)verts.size();
        unordered_map<int,int> id;
        id.reserve(k*2);
        for(int i=0;i<k;i++) id[verts[i]]=i;
        vector<vector<int>> adj(k);
        for(auto &e: compEdges[cid]){
            int x = id[e.fi], y = id[e.se];
            adj[x].pb(y); adj[y].pb(x);
        }

        // bipartite check
        vector<int> color(k, -1);
        bool bad = false;
        queue<int> q;
        color[0]=0; q.push(0);
        while(!q.empty() && !bad){
            int u = q.front(); q.pop();
            for(int v: adj[u]){
                if(color[v]==-1){
                    color[v]=color[u]^1;
                    q.push(v);
                }else if(color[v]==color[u]){
                    bad = true; break;
                }
            }
        }
        isOdd[cid] = bad ? 1 : 0;

        // register this cyclic component to its vertices
        for(int vtx: verts) compsOf[vtx].pb(cid);
    }

    // DSU over cyclic components; merge those sharing a vertex
    DSU dsu(C);
    for(int v=1; v<=n; ++v){
        auto &L = compsOf[v];
        for(size_t i=1;i<L.size();++i) dsu.u_(L[0], L[i]);
    }

    // group attributes
    vector<char> grpHasOdd(C, 0);
    vector<int> grpVal(C, -2); // -2 unknown group (no preset yet), else required constant, for odd group must be 0
    vector<char> grpBad(C, 0);

    for(int cid=0; cid<C; ++cid){
        if(!isCyclic[cid]) continue;
        int r = dsu.f(cid);
        grpHasOdd[r] = grpHasOdd[r] | isOdd[cid];
    }

    // Apply presets to groups
    for(int v=1; v<=n; ++v){
        if(compsOf[v].empty()){
            continue; // not in any cyclic group
        }
        int r = dsu.f(compsOf[v][0]);
        if(grpHasOdd[r]){
            // forced 0
            if(a[v] != -1 && a[v] != 0){
                grpBad[r] = 1;
            }
            // record that the group constant is 0
            if(grpVal[r] == -2) grpVal[r] = 0;
            else if(grpVal[r] != 0) grpBad[r] = 1;
        }else{
            // bipartite-only group: all vertices equal to same constant
            if(a[v] != -1){
                if(grpVal[r] == -2) grpVal[r] = a[v];
                else if(grpVal[r] != a[v]) grpBad[r] = 1;
            }
        }
    }

    // Count contributions
    auto mulmod = [&](ll x, ll y)->ll{
        return (x*y) % MOD;
    };
    ll ans = 1;

    // free tree-like unknown vertices
    for(int v=1; v<=n; ++v){
        if(compsOf[v].empty() && a[v] == -1){
            ans = mulmod(ans, (V % MOD));
        }
    }

    // group factors
    vector<char> seen(C, 0);
    for(int cid=0; cid<C; ++cid){
        if(!isCyclic[cid]) continue;
        int r = dsu.f(cid);
        if(seen[r]) continue;
        seen[r]=1;
        if(grpBad[r]){
            ans = 0; break;
        }
        if(grpHasOdd[r]){
            // forced 0; already checked presets; contributes 1
            continue;
        }else{
            // bipartite-only; if no preset -> V choices
            if(grpVal[r] == -2){
                ans = mulmod(ans, (V % MOD));
            } // else fixed, factor 1
        }
    }

    out(ans % MOD);
  }
  return 0;
}
