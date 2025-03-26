// // coded by Cocane

// #include <bits/stdc++.h>

// #define ll long long
// #define forn(i, n) for (int i = 0; i < n; i++)
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

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vi a(n), b(n);

//         read(a);
//         read(b);

//         unordered_map<int, int> f1, f2;

//         for (int i = 0; i < n; i++) {
//             f1[a[i]]++;
//             f2[b[i]]++;
//         }

//         int f1_size = f1.size(), f2_size = f2.size();

//         if ((f2_size == 1 && f1_size < 3) || (f2_size == 2 && f1_size < 2)) {
//             out("NO");
//         } else {
//             out("YES");
//         }
//     }
//     return 0;
// }

















#include <bits/stdc++.h>
using namespace std;

long long findMaximumGreatness(vector<long long>& arr) {
    int n = (int)arr.size();
    sort(arr.begin(), arr.end());

    int i = 0, j = 1, matches = 0;
    while(j < n && i < n){
        if(arr[j] > arr[i]) {
            matches++;
            i++; 
            j++;
        } else {
            j++;
        }
    }
    cout << matches << "\n";
    return matches;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> arr = {1, 3, 5, 2, 1, 3, 1};
    cout << "Result => " << findMaximumGreatness(arr) << "\n";
    return 0;
}

First

