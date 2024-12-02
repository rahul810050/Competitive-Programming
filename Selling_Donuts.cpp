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
				int n, m;
        cin >> n >> m;

        vi v1(n), v2(m);
        read(v1);
        read(v2);

        int sad = 0;

        for (int i = 0; i < m; i++) {
            int idx = v2[i] - 1;
            if (idx >= 0 && idx < n) {
                if (v1[idx] > 0) {
                    v1[idx]--;
                } else {
                    sad++;
                }
            } else {
                sad++;
            }
        }

        out(sad);
		}
		return 0;
}