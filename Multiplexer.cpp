// // coded by Cocane

// #include <bits/stdc++.h>

// #define ll long long
// #define forn(i, n) for (int i = 0; i < n; i++)
// #define for1(i, n) for (int i = 1; i <= n; i++)
// #define foru(i, n) for (int i = n - 1; i >= 0; i--)
// #define fi first
// #define se second
// #define all(x) (x).begin(), (x).end()
// #define pb push_back
// #define read(a) for (auto &i : a) cin >> i
// #define out(ans) cout << ans << endl
// #define yn(a) cout << (a ? "YES" : "NO") << endl

// using namespace std;

// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef double dl;

// int add(int a, int b) { return a + b; }
// int subst(int a, int b) { return a - b; }
// ll multip(ll a, ll b) { return a * b; }
// int divion(int a, int b) { return (b == 0) ? 0 : a / b; }
// int mxVal(int a, int b) { return max(a, b); }
// int mnVal(int a, int b) { return min(a, b); }

// void solve() {
//     int testCases;
//     cin >> testCases;

//     while (testCases--) {
//         int size, factor;
//         cin >> size >> factor;
//         vi arr(size);
//         read(arr);

//         if (factor == 1) {
//             map<int, int> freq;
//             int best = 0;
//             for (int mun : arr) {
//                 freq[mun] = add(freq[mun], 1);
//                 best = mxVal(best, freq[mun]);
//             }
//             out(best);
//             continue;
//         }

//         map<int, int> freq;
//         for (int mun : arr) {
//             freq[mun] = add(freq[mun], 1);
//         }

//         map<pair<int, int>, vi> conMap;
//         for (int mun : arr) {
//             pair<int, int> inPair = make_pair(mun, multip(mun, factor));
//             conMap[inPair].pb(1);

//             if (mun % factor == 0) {
//                 pair<int, int> decreasePair = make_pair(divion(mun, factor), mun);
//                 conMap[decreasePair].pb(-1);
//             }
//         }

//         int besRes = 0;
//         if (!freq.empty()) {
//             map<int, int>::iterator it = max_element(freq.begin(), freq.end(),
//                                                     [](const pair<int, int> &a, const pair<int, int> &b) {
//                                                         return a.second < b.second;
//                                                     });
//             besRes = mxVal(besRes, it->second);
//         }

//         for (map<pair<int, int>, vi>::iterator it = conMap.begin(); it != conMap.end(); ++it) {
//             int currSum = 0, locaBes = 0;
//             for (size_t i = 0; i < it->second.size(); i++) {
//                 currSum = mxVal(0, add(currSum, it->second[i]));
//                 locaBes = mxVal(locaBes, currSum);
//             }

//             int candiifreq = add(freq[it->first.second], locaBes);
//             besRes = mxVal(besRes, candiifreq);
//         }

//         out(besRes);
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     solve();
//     return 0;
// }
