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

		int N;
    cin >> N;
    
    vector<vi> photos(5, vi(N));  
    
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> photos[i][j];
        }
    }

    vector<map<int, int>> freq(N);
    
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < N; ++j) {
            freq[j][photos[i][j]]++;  
        }
    }

    vi orderOrg(N, -1); 
    set<int> alreadyUsed;                  
    
    for (int i = 0; i < N; ++i) {
        int mxFreq = 0;
        int currKid = -1;

        for (auto &it : freq[i]) {
            if (it.se > mxFreq && alreadyUsed.find(it.fi) == alreadyUsed.end()) {
                mxFreq = it.se;
                currKid = it.fi;
            }
        }

        orderOrg[i] = currKid;
        alreadyUsed.insert(currKid);  
    }

    for (int i = 0; i < N; ++i) {
        cout << orderOrg[i] <<endl;
    }
		return 0;
}