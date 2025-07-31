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

vll add(vi v){
  vll vec;
  ll sum = 0;
  for(auto it: v){
    sum += it;
  }

  for(int i = 0; i < v.size(); i++) vec.pb(sum);
  return vec;
}

vll add1(vll v){
  vll vec;
  ll sum = 0;
  for(auto it: v){
    sum += it;
  }

  for(int i = 0; i < v.size(); i++) vec.pb(sum);
  return vec;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    vi A(N), B(N);
    read(A);
    read(B);

    vll vec = add(A);
    vll vec1 = add(B);

    

    const int mx = 100;
    vector<ll> con(mx+1, 0);
    forn(i, N){
      if(A[i] > 0 && B[i] <= mx){
        con[B[i]] += A[i];
      }
    }
    vll pp(mx+1, 0);
    pp[0] = 0;
    for1(l, mx){
      pp[l] = pp[l-1] + con[l];
    }

    vll vec2;

    for(int i = 0; i < A.size(); i++){
      vec2.pb(vec[i]+ vec1[i]);
    }

    

    ll ans = 0;
    for(int L = 1; L <= mx; L++){
      ll S = pp[L];
      ans = max(ans, S - L);
    }

    vll vvv = add1(vec2);
    ll res = accumulate(all(vvv), 0);
    out(ans);
  }
  return 0;
}
