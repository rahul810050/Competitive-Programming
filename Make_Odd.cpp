// // coded by Cocane

// #include <bits/stdc++.h>

// #define ll long long
// #define forn(i, n) for (int i = 0; i < n; i++)
// #define for1(i, n) for (int i = 1; i <= n; i++)
// #define foru(i, n) for (int i = n - 1; i >= 0; i--)
// #define fi first
// #define se second
// #define all(x) (x).begin(), (x).end()
// #define allp(x) (x).begin(), (x).begin() + (x).size() / 2, (x).rbegin()
// #define pb push_back
// #define ppb pop_back
// #define read(a) for (auto &i : a) cin >> i
// #define out(ans) cout << ans << endl
// #define yn(a) cout << (a ? "YES" : "NO") << endl

// using namespace std;

// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef double dl;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         string a, b;
//         cin >> n >> a >> b;

//         ll aInt = 0, bInt = 0;
//         bool conflict = false;

//         for (int i = 0; i < n; i++) {
//             aInt += (a[i] - '0');
//             bInt += (b[i] - '0');

//             if (!conflict && ((a[i] == '0' && b[i] == '1') || (a[i] == '1' && b[i] == '0'))) {
//                 conflict = true;
//             }
//         }

//         if ((aInt % 2 == 0 && bInt % 2 == 0 && conflict) || (aInt % 2 == 1 && bInt % 2 == 1)) {
//             out("YES");
//         } else {
//             out("NO");
//         }
//     }
//     return 0;
// }


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

		int t;
		cin>>t;
		while(t--){
				
		}
		return 0;
}