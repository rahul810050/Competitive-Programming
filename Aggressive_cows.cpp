// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 10;
// int n, c;
// int x[N];

// bool aggressiveCow(int dis) {
//     int last_position = x[0];
//     int cows_count = 1;

//     for (int i = 1; i < n; i++) {
//         if (x[i] - last_position >= dis) {
//             cows_count++;
//             last_position = x[i];
//         }
//         if (cows_count >= c) return true;
//     }
//     return false;
// }

// int main() {
//     int t;
//     cin >> t;

//     while (t--) {
//         cin >> n >> c;

//         for (int i = 0; i < n; i++) {
//             cin >> x[i];
//         }

//         sort(x, x + n);

//         int lo = 1, hi = x[n-1] - x[0], mid;
//         int ans = 0;

//         while (lo <= hi) {
//             mid = (lo + hi) / 2;
//             if (aggressiveCow(mid)) {
//                 ans = mid;
//                 lo = mid + 1;
//             } else {
//                 hi = mid - 1;
//             }
//         }

//         cout << ans << endl;
//     }

//     return 0;
// }

// coded by Cocane

#include <bits/stdc++.h>

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define foru(i, n) for (int i = n - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define allp(x) (x).begin(), (x).begin() + (x).size() / 2, (x).rbegin()
#define pb push_back
#define ppb pop_back
#define read(a)      \
   for (auto &i : a) \
   cin >> i
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

const int N = 1e5+10;

ll n, c;
ll stalls[N];

bool aggressiveCow(int hi){
   ll last_pos = stalls[0];
   ll cow_count = 1;
   for (ll i = 1; i < n; i++)
   {
      if(stalls[i] - last_pos >= hi){
         cow_count++;
         last_pos = stalls[i];
      }
      if(cow_count >= c) return true;
   }
   return false;
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   int t;
   cin >> t;
   while (t--)
   {
      cin>>n>>c;
      forn(i, n) cin>>stalls[i];
      sort(stalls, stalls+n);

      ll lo = 1, hi = stalls[n-1] - stalls[0] , mid;
      ll ans=0;
      while (lo <= hi)
      {
         mid = (hi + lo)/ 2;
         if(aggressiveCow(mid)){
            lo = mid+1;
            ans = mid;
         } else{
            hi = mid-1;
         }
      }
      cout<<ans<<endl;
   }
   return 0;
}