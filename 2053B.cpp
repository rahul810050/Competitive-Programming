// // coded by Cocane

// #include<bits/stdc++.h>

// #define ll long long
// #define forn(i, n) for(int i = 0; i < n; i++)
// #define for1(i, n) for(int i = 1; i <= n; i++)
// #define foru(i, n) for(int i = n - 1; i >= 0; i--)
// #define fi first
// #define se second
// #define all(x) (x).begin(),(x).end()
// #define allp(x) (x).begin(), (x).begin() + (x).size()/2, (x).rbegin()
// #define pb push_back
// #define ppb pop_back
// #define read(a) for(auto &i : a) cin >> i
// #define out(ans) cout << ans << endl
// #define yn(a) cout << (a ? "YES" : "NO") << endl

// using namespace std;

// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef double dl;

// const int MAX = 4e5 + 5;
// int l[MAX], r[MAX], nsum[MAX], frequency[MAX];

// void solve() {
//     int n;
//     cin >> n;

//     for1(i, 2 * n) nsum[i] = frequency[i] = 0;

//     for1(i, n) {
//         cin >> l[i] >> r[i];
//         if (l[i] == r[i]) {
//             nsum[l[i]] = 1;
//             frequency[l[i]]++;
//         }
//     }

//     for1(i, 2 * n) nsum[i] += nsum[i - 1];

//     for1(i, n) {
//         if (l[i] == r[i]) {
//             cout << (frequency[l[i]] <= 1 ? '1' : '0');
//         } else {
//             int total = nsum[r[i]] - nsum[l[i] - 1];
//             cout << (total < (r[i] - l[i] + 1) ? '1' : '0');
//         }
//     }

//     cout << endl;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;
//     while (t--) solve();

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

        int n; cin>>n;
        vi v(n);
        read(v);
        auto it = min_element(all(v));
        int x = it - v.begin();
        cout<<x<<endl;
        return 0;
}