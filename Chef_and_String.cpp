// #include <bits/stdc++.h>

// #define ll long long
// #define forn(i, n) for(int i = 0; i < n; i++)
// #define for1(i, n) for(int i = 1; i <= n; i++)
// #define foru(i, n) for(int i = n-1; i >= 0; i--)
// #define fi first
// #define se second
// #define all(x) (x).begin(), (x).end()
// #define pb push_back
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
//         string s;
//         cin >> s;
//         int n = s.length();

//         string leftShift = s.substr(1,s.size()) + s.substr(0,1);
// 				string rightShift = s.substr(s.size()-1,s.size()) + s.substr(0,s.size()-1);
// 				if(leftShift == rightShift) cout<<"YES"<<endl;
// 				else cout<<"NO"<<endl;
//     }
//     return 0;
// }


#include <iostream>
using namespace std;

int main() {
    long long A, B, C, X;
    
    cin >> A >> B >> C >> X;
    
    long long cuboiVol = A * B * C;
    
    long long cubeVol = X * X * X;
    
    if (cuboiVol > cubeVol) {
        cout << "Cuboid" << endl;
    } else if (cubeVol > cuboiVol) {
        cout << "Cube" << endl;
    } else {
        cout << "Equal" << endl;
    }
    
    return 0;
}
