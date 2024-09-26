// // // coded by Cocane

// // #include<bits/stdc++.h>

// // #define ll long long
// // #define forn(i, n) for(int i = 0; i < n; i++)
// // #define for1(i, n) for(int i = 1; i <= n; i++)
// // #define foru(i, n) for(int i = n-1; i >= 0; i--)
// // #define fi first
// // #define se second
// // #define all(x) (x).begin(),(x).end()
// // #define pb push_back

// // using namespace std;

// // typedef vector<int> vi;
// // typedef vector<ll> vll;

// // int main() {
// //     ios::sync_with_stdio(false);
// //     cin.tie(NULL);

// //     int n;
// //     cin >> n;

// //     vi even, odd;

// //     forn(i, n) {
// //         int x;
// //         cin >> x;
// //         if (x % 2 == 0) {
// //             even.pb(x);
// //         } else {
// //             odd.pb(x);
// //         }
// //     }

// //     ll sum = accumulate(all(even), 0LL);

// //     sort(all(odd), greater<int>());

// //     int len = odd.size();

// //     if (len % 2 == 0) {
// //         for (auto &it : odd) sum += it;
// //     } else {
// //         for (auto &it : odd) sum += it;
// //         sum -= odd.back(); 
// //     }

// //     cout << sum << endl;

// //     return 0;
// // }



// // coded by Cocane

// #include<bits/stdc++.h>

// #define ll long long
// #define forn(i, n) for(int i = 0; i < n; i++)
// #define for1(i, n) for(int i = 1; i <= n; i++)
// #define foru(i, n) for(int i = n-1; i >= 0; i--)
// #define fi first
// #define se second
// #define all(x) (x).begin(),(x).end()
// #define allp(x) (x).begin(), (x).begin() + (x).size()/2, (x).rbegin()
// #define pb push_back
// #define out(ans) cout<<ans<<endl
// #define yn(a) cout<< (a ? "YES": "NO") <<endl

// using namespace std;

// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef double dl;

// ll factorial(int n) {
//     long long result = 1;
//     for (int i = 2; i <= n; ++i) {
//         result *= i;
//     }
//     return result;
// }


// int main(){
// 		ios::sync_with_stdio(false);
// 		cin.tie(NULL);

// 		int t;
// 		cin>>t;
// 		while(t--){
// 				int n; cin>>n;

// 				ll ways = factorial(n);

// 				cout<<ways<<endl;
// 		}
// 		return 0;
// }


// coded by Cocane

// coded by Cocane

// coded by Cocane

// #include<bits/stdc++.h>

// #define ll long long
// #define forn(i, n) for(int i = 0; i < n; i++)
// #define for1(i, n) for(int i = 1; i <= n; i++)
// #define foru(i, n) for(int i = n-1; i >= 0; i--)
// #define fi first
// #define se second
// #define all(x) (x).begin(),(x).end()
// #define allp(x) (x).begin(), (x).begin() + (x).size()/2, (x).rbegin()
// #define pb push_back
// #define out(ans) cout<<ans<<endl
// #define yn(a) cout<< (a ? "YES": "NO") <<endl

// using namespace std;

// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef double dl;


// int main(){
// 		ios::sync_with_stdio(false);
// 		cin.tie(NULL);

// 		int n, N;
//     cin >> n >> N;

//     vi x(n);
//     for (int i = 0; i < n; i++) {
//         cin >> x[i];
//     }

//     unordered_set<int> seen;

//     sort(x.begin(), x.end());
//     x.erase(unique(x.begin(), x.end()), x.end());

//     for (int i = 0; i < x.size(); i++) {
//         int start = x[i];

//         for (int j = start; j <= N; j += start) {
//             seen.insert(j);
//         }
//     }

//     cout << seen.size() << endl;
// 		return 0;
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
#define out(ans) cout<<ans<<endl
#define yn(a) cout<< (a ? "YES": "NO") <<endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;


bool can_divide(vi & a, int n, int k, int mid) {
    int curr_sum = 0;
    int count = 1;  
    
    for (int i = 0; i < n; i++) {
        if (curr_sum + a[i] > mid) {
            count++;
            curr_sum = a[i];
            if (count > k) {
                return false;
            }
        } else {
            curr_sum += a[i];
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vi a(n);
    int mxPiece = 0;
    int total_sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total_sum += a[i];
        mxPiece = max(mxPiece, a[i]);
    }

    int l = mxPiece, r = total_sum;
    int ans = mxPiece;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (can_divide(a, n, k, mid)) {
            ans = mid; 
            l = mid + 1;  
        } else {
            r = mid - 1;  
        }
    }

    cout << ans << endl;

    return 0;
}



