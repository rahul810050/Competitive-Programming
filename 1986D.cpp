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
        int n;
        string s;
        cin>>n>>s;

        if(n == 2) {
            cout << stoi(s) << endl;  
        }
        else if(n == 3){
            if(s[0] == '0' || s[2] == '0'){  
                cout << 0 << endl;  
            }
            else{
                int str1 = stoi(s.substr(0,2));
                int str2 = stoi(s.substr(1,2));

                int mini1 = min(str1 + (s[2] - '0'), str1 * (s[2] - '0'));
                int mini2 = min(str2 + (s[0] - '0'), str2 * (s[0] - '0'));

                cout << min(mini1, mini2) << endl;
            }
        }
        else{
            int mn = *min_element(all(s)) - '0';

            if(mn == 0) {
                cout << 0 << endl;  
            }
            else {
                vector<pair<int,int>> v;
                vll totals;

                for (int i = 0; i < n-1; i++) {
                    v.pb({stoi(s.substr(i, 2)), i});
                }

                for (int i = 0; i < v.size(); i++) {
                    ll each_sum = v[i].fi;
                    int sec = v[i].se;

                    for (int j = 0; j < n; j++) {
                        if((j != sec) && (j != sec+1) && s[j] != '1'){
                            each_sum += (s[j] - '0');  
                        }
                    }
                    totals.pb(each_sum); 
                }

                cout << *min_element(all(totals)) << endl;
            }
        }
    }
    return 0;
}
