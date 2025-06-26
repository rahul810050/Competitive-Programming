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
    int n, q;
    cin >> n >> q;

    vector<vector<int>> pre1(n + 1, vector<int>(26, 0));
    vector<vector<int>> pre2(n + 1, vector<int>(26, 0));

    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        pre1[i][c - 'a']++;

        for (int j = 0; j < 26; j++)
            pre1[i][j] += pre1[i - 1][j];
    }
    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        pre2[i][c - 'a']++;

        for (int j = 0; j < 26; j++)
            pre2[i][j] += pre2[i - 1][j];
    }
    while (q--){
        int l, r;
        cin >> l >> r;

        int dif = 0;

        for (int c = 0; c < 26; c++){
            int v1 = pre1[r][c] - pre1[l - 1][c];
            int v2 = pre2[r][c] - pre2[l - 1][c];

            dif += abs(v1 - v2);
        }
        cout << dif / 2 <<endl;
    }
  }
  return 0;
}