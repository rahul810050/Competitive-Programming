#include<bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n-1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
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
    cin >> t;
    while(t--){
        // int num;
        // cin >> num;
        string s; cin>>s;

				int ct0 = 0, ct1 = 0;

        for (int i = 0; i < s.length(); i++) {
            if(s[i] == '1') ct1++;
						else ct0++;
        }

        if(ct1 == 1 || ct0 == 1) cout<<"Yes"<<endl;
				 else cout << "No" << endl;
        
    }
    return 0;
}
