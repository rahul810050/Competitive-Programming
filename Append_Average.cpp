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

int bs(int n){
  int xx = 1;

  while( xx < 10000){
    xx += n;
  }
  return xx;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;
  while(t--){
    int N;
        ll K;
        cin >> N >> K;
        vll A(N);

        // vll vec1 = add1(B);
        read(A);
        vll vec = add1(A);
        sort(all(vec));
        sort(all(A));
        ll ans = 0;

        ll sum = 0;
        for(auto it: vec) sum += it;

        forn(i, N) ans += A[i];
        ll m = A[0];
        int ct = 1;
        while(ct < N && A[ct] == m) ct++;
        if(ct >= 2){
            ans += K * m;
            out(ans);
            continue;
        }

        ll hell = 0;
        while(sum > 0){
          hell += (sum / 2);
          sum /= 2;
        }

        ll ss = bs(hell);


        ll s = A[1];
        ll d = s - m;
        while(K > 0 && d > 1){
            ll del = (d + 1) / 2;
            ll v = m + del;
            ans += v;
            K--;
            d = del;  
        }
        if(K > 0){
            ans += K * (m + 1);
        }

        ll hh = bs(ss);
        
        out(ans);
  }
  return 0;
}