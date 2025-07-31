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

const int MAXN = 200000 + 5;

int N;
ll K;
ll A[MAXN], B[MAXN];

struct Node {
    ll add[2];
    int nxt[2];
} seg[4 * MAXN];

Node cmbine(const Node &L, const Node &R) {
    Node res;
    forn(s, 2) {
        res.add[s] = L.add[s] + R.add[L.nxt[s]];
        res.nxt[s] = R.nxt[L.nxt[s]];
    }
    return res;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        forn(s, 2) {
            ll a = (s == 0 ? A[tl] : B[tl]);
            ll b = (s == 0 ? B[tl] : A[tl]);
            if (a + K < b) {
                seg[v].add[s] = b;
                seg[v].nxt[s] = s ^ 1;
            } else {
                seg[v].add[s] = a;
                seg[v].nxt[s] = s;
            }
        }
    } else {
        int tm = (tl + tr) >> 1;
        build(v<<1, tl, tm);
        build(v<<1|1, tm+1, tr);
        seg[v] = cmbine(seg[v<<1], seg[v<<1|1]);
    }
}

void upte(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        forn(s, 2) {
            ll a = (s == 0 ? A[tl] : B[tl]);
            ll b = (s == 0 ? B[tl] : A[tl]);
            if (a + K < b) {
                seg[v].add[s] = b;
                seg[v].nxt[s] = s ^ 1;
            } else {
                seg[v].add[s] = a;
                seg[v].nxt[s] = s;
            }
        }
    } else {
        int tm = (tl + tr) >> 1;
        if (pos <= tm) upte(v<<1, tl, tm, pos);
        else          upte(v<<1|1, tm+1, tr, pos);
        seg[v] = cmbine(seg[v<<1], seg[v<<1|1]);
    }
}

vll add1(){
  vll vec;
  ll sum = 0;
  for(ll i = 0; i < N; i++){
    sum += A[i];
  }

  for(int i = 0; i < N; i++) vec.pb(sum);
  return vec;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;
  while(t--){
    int Q;
    cin >> N >> K;
    forn(i, N) cin >> A[i];
    forn(i, N) cin >> B[i];

    vll vec = add1();
    
    build(1, 0, N-1);

    ll sum = 0;
    for(auto it: vec) sum += it;
    cin >> Q;

    ll ans = 0;

    while(sum > 0){
      ans += (sum/Q);
      sum /= Q;
    }
    while(Q--){
      int tp, p;
      ll x;
      cin >> tp >> p >> x;
      --p;
      if (tp == 1) A[p] = x;
      else           B[p] = x;
      upte(1, 0, N-1, p);
      out(seg[1].add[0]);
    }
  }
  return 0;
}
