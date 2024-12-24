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
// #define ppb pop_back
// #define read(a) for (auto &i : a) cin >> i
// #define out(ans) cout << ans << endl
// #define yn(a) cout << (a ? "YES" : "NO") << endl

// using namespace std;

// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef double dl;

// string remove33(string s, int pos) {
//     return s.substr(0, pos) + s.substr(pos + 2);
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;
//     while (t--) {
//         ll x;
//         cin >> x;

//         string s = to_string(x);

//         if (x % 33 == 0) {
//             cout << "YES" << endl;
//             continue;
//         }

//         bool f = false;
//         for (int i = 0; i < s.size() - 1; i++) {
//             if (s[i] == '3' && s[i + 1] == '3') {
//                 string newStr = remove33(s, i);

//                 ll newNumber = stoll(newStr);

//                 if (newNumber % 33 == 0) {
//                     f = true;
//                     break;
//                 }
//             }
//         }

//         yn(f);
//     }
//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;
int main(){
    int test,i=0;
    cin>>test;
    for(i=0; i<test; i++){
        string s;
        cin>>s;
        int j,k;
        int n=s.length();
        for(j=0; j<n; j++){
            if(s[j]=='0'){
                break;
            }
        }
        // cout<<j<<endl;
        cout<<"1 "<<n<<" ";
        if(j==n){
            cout<<"1 1"<<endl;
            continue;
        }
        int req;
        int len=n-j;
        int maxi=0;
        for(k=0; k<j; k++){
            if(s[k]=='1'){
                int l=1;
                while(l<len && (s[k+l]-'0')^(s[j+l]-'0')==1){
                    l++;
                }
                // cout<<k<<" "<<l<<endl;
                if(l>maxi){
                    req=k;
                    maxi=l;
                }
            }
        }
        cout<<req+1<<" "<<req+len<<endl;
    }
}