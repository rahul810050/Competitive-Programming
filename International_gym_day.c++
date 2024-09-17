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

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;
    
//     while (t--) {
//         int D, X, Y;
//         cin >> D >> X >> Y;

//         if (Y >= X) {
//             cout << 0 << endl;
//             continue;
//         }
        
//         int ct = 0;
//         bool flag = false;
        
//         while (Y > 0) {
//             ct++;
//             Y--;

//             double pay = X * max(0, (100 - D * ct)) / 100.0;
            
//             if (Y >= floor(pay)) {
//                 cout << ct << endl;
//                 flag = true;
//                 break;
//             }
//         }
        
//         if (!flag) {
//             cout << -1 << endl;
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
				int N;
        cin >> N;
        
        vi A(N); 
        vi B(N); 
        
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        
        int count = 1; 
        int maxSpeed = B[N-1]; 
        
        for (int i = N - 2; i >= 0; i--) {
            if (B[i] > maxSpeed) {
                count++;
                maxSpeed = B[i]; 
            }
        }
        
        cout << count << endl;
		}
		return 0;
}