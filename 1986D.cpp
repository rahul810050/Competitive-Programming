// coded by Cocane

#include<bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        if (s[0] == '0') {
            cout << 0 << endl;
        } else if (n == 2) {
            cout << s << endl;
        } else if (n == 3) {
            ll mn_sum = 0;
            if(s[1] == '0') {
							int x = s[0] - '0'; 
							int y = stoi(s.substr(1, 2)); 
							int p1 = min((x + y), (x * y));
							int a = s[2] - '0';
							int b = stoi(s.substr(0,1));
							int p2 = min((a + b), (a * b));
							cout<<min(p1,p2)<<endl;
					  }
            else{
							int x = s[0] - '0'; 
							int y = stoi(s.substr(1, 2)); 
							int p1 = min((x + y), (x * y));
							int a = s[2] - '0';
							int b = stoi(s.substr(0,1));
							int p2 = min((a + b), (a * b));
							cout<<min(p1,p2);
						}
        } else if (n > 3) {
            if (s.find('0') == string::npos) { 
                ll mn_sum = 0;
                for (int i = 0; i < n; i++) {
                    ll addition = mn_sum + (s[i] - '0');
                    ll multiplication = mn_sum * (s[i] - '0');
                    mn_sum = min(addition, multiplication);
                }
                cout << mn_sum << endl;
            } \
        }
    }
    return 0;
}
