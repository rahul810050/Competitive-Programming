#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;
using pll = pair<long long,long long>;
using dl = double;
#define read(x) cin >> x
#define read2(a,b) cin >> a >> b
#define read3(a,b,c) cin >> a >> b >> c
#define rfor(i,a,b) for(int i = (a); i >= (b); --i)
#define readv(v,n) for(auto &it : v) cin >> it;
#define print(x) cout << x << '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void buildGraph(int N, vector<vector<int>>& edges, vector<vi>& adj, vi& deg){
    adj.assign(N, vi());
    deg.assign(N, 0);
    for(auto& e : edges){
        int u = e[0]-1, v = e[1]-1;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }
}

queue<int> initQueue(int N, vi& deg){
    queue<int> q;
    for(int i = 0; i < N; i++)
        if(deg[i] <= 1) q.push(i);
    return q;
}

void processNode(int u, vector<vi>& adj, vi& deg, vll& acc, vector<bool>& done, queue<int>& q){
    done[u] = true;
    for(int v : adj[u]){
        if(done[v]) continue;
        acc[v] += acc[u];
        deg[v]--;
        if(deg[v] <= 1) q.push(v);
    }
}

vll computeAcc(int N, vll& A, vector<vi>& adj, vi& deg){
    vll acc(A.begin(), A.end());
    vector<bool> done(N, false);
    queue<int> q = initQueue(N, deg);
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(done[u]) continue;
        processNode(u, adj, deg, acc, done, q);
    }
    return acc;
}

ll calcScore(vll& acc){
    sort(all(acc));
    ll res = 0;
    for(int i = 0; i < (int)acc.size(); i++)
        res += acc[i] * (ll)(i+1);
    return res;
}

long long solve(int N, int M, vector<long long> A, vector<vector<int>> edges){
    vector<vi> adj;
    vi deg;
    buildGraph(N, edges, adj, deg);
    vll acc = computeAcc(N, A, adj, deg);
    return calcScore(acc);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    read2(n, m);
    vll a(n);
    readv(a, n);
    vector<vector<int>> edges(m, vector<int>(2));
    for(auto& e : edges) read2(e[0], e[1]);
    print(solve(n, m, a, edges));
    return 0;
}