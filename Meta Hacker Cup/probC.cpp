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
  if(!(cin >> T)) return 0;
  for1(tc, T){
    int N;
    cin >> N;
    vector<unsigned int> A(N);
    forn(i, N) cin >> A[i];

    // prefix XORs S[0..N]
    vector<unsigned int> S(N+1);
    S[0] = 0;
    for(int i = 1; i <= N; ++i){
      S[i] = S[i-1] ^ A[i-1];
    }

    // baseline = sum_{L=1..N} L*(N+1-L) = N*(N+1)*(N+2)/6
    __int128 n = N;
    __int128 baseline128 = n * (n + 1) * (n + 2) / 6;
    long long baseline = (long long) baseline128;

    sort(S.begin(), S.end());

    __int128 sub128 = 0; // will hold sum of C(k,2) + C(k,3) over all distinct S-values
    for(int i = 0; i <= N; ){
      int j = i+1;
      while(j <= N && S[j] == S[i]) ++j;
      long long k = j - i; // frequency
      if(k >= 2){
        __int128 c2 = (__int128)k * (k - 1) / 2;
        sub128 += c2;
      }
      if(k >= 3){
        __int128 c3 = (__int128)k * (k - 1) * (k - 2) / 6;
        sub128 += c3;
      }
      i = j;
    }

    long long sub = (long long) sub128;
    long long ans = baseline - sub;
    cout << "Case #" << tc << ": " << ans << "\n";
  }

  return 0;
}
