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
    string s, txt;
        getline(cin, s);
        getline(cin, txt);

        unordered_map<char, int> ct;
        for (char c : txt) {
            if (isalpha(c)) ct[tolower(c)]++;
        }

        vector<pair<int, char>> v;
        for (char c = 'a'; c <= 'z'; ++c) {
            v.push_back({ct[c], c});
        }

        sort(v.begin(), v.end());

        unordered_map<char, char> p;
        for (int i = 0; i < 26; ++i) {
            p[v[i].second] = s[i];
        }

        string ans;
        for (char c : txt) {
            if (islower(c)) {
                ans += p[c];
            } else if (isupper(c)) {
                ans += toupper(p[tolower(c)]);
            } else {
                ans += c;
            }
        }

        cout << ans << endl;
  }
  return 0;
}