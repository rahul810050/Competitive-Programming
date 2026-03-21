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

const ll INF = 1e18;

int lb(vll& v, int st, ll t){
    return (int)(lower_bound(v.begin()+st, v.end(), t) - v.begin());
}

ll rangeSum(vll& pfx, int l, int r){
    return pfx[r+1] - pfx[l];
}

bool getSqrt(ll n, ll& rt){
    rt = (ll)sqrtl(n);
    while(rt * rt > n) rt--;
    while((rt+1)*(rt+1) <= n) rt++;
    return rt * rt == n && rt >= 2;
}

bool overflows(ll a, ll b){
    return a > INF / b;
}

void buildFreq(vll& A, vll& vals, vll& fr){
    map<ll,ll> mp;
    for(auto x : A) mp[x]++;
    for(auto& [v,f] : mp){
        vals.push_back(v);
        fr.push_back(f);
    }
}

vll buildPfx(vll& fr){
    int M = fr.size();
    vll pfx(M+1, 0);
    for(int i = 0; i < M; i++) pfx[i+1] = pfx[i] + fr[i];
    return pfx;
}

ll stdProg(vll& vals, vll& pfx, int K){
    int M = vals.size();
    ll res = 0;
    for(int i = 0; i < M; i++){
        ll b = vals[i];
        if(b < 2) continue;
        int cur = i;
        ll pw = b;
        for(int s = 0; s < K; s++){
            if(overflows(pw, b)) break;
            pw *= b;
            int p = lb(vals, cur, pw);
            if(p == M) break;
            if(vals[p] == pw)
                res = max(res, rangeSum(pfx, cur, p));
            cur = p;
        }
    }
    return res;
}

ll sqProg(vll& vals, vll& pfx, int K){
    int M = vals.size();
    ll res = 0;
    for(int i = 0; i < M; i++){
        ll rt;
        if(!getSqrt(vals[i], rt)) continue;
        ll mult = vals[i], cv = vals[i];
        int cur = i;
        for(int s = 0; s < K; s++){
            if(overflows(cv, mult)) break;
            ll nxt = cv * mult;
            int p = lb(vals, cur, nxt);
            if(p == M || vals[p] != nxt) break;
            res = max(res, rangeSum(pfx, cur, p));
            cur = p;
            cv = nxt;
        }
    }
    return res;
}

long long solve(int N, int K, vector<long long> A){
    vll vals, fr;
    buildFreq(A, vals, fr);
    vll pfx = buildPfx(fr);
    return max(stdProg(vals, pfx, K), sqProg(vals, pfx, K));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    read2(n, k);
    vll a(n);
    readv(a, n);
    print(solve(n, k, a));
    return 0;
}