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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  for1(tc, T){
    int N;
    cin >> N;
    vll A(N);
    for(int i=0;i<N;i++) cin >> A[i];

    ll lo = 0;
    ll hi = 0;
    for(int i=0;i<N;i++) hi = max(hi, A[i]);

    auto feasible = [&](ll h)->bool{
      int i = 0;
      while(i < N){
        // start component at i
        ll comp_min = A[i];
        int j = i;
        while(j+1 < N && llabs(A[j+1] - A[j]) <= h){
          j++;
          comp_min = min(comp_min, A[j]);
        }
        if(comp_min > h) return false;
        i = j+1;
      }
      return true;
    };

    while(lo < hi){
      ll mid = lo + (hi - lo) / 2;
      if(feasible(mid)) hi = mid;
      else lo = mid + 1;
    }

    cout << "Case #" << tc << ": " << lo << "\n";
  }

  return 0;
}
