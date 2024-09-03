// coded by cocane

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
        int n; 
        cin >> n;

        vector<pair<int,int>> v(n+1);
        for (int i = 1; i <= n; i++) {
					v[i].fi = i;
            cin >> v[i].se;
        }

        bool present = false;

        for (int i = 1; i <= n; i++)
				{
					for (int j = i+1; j <= n; j++)
					{
						if(v[i].fi == v[j].se && v[i].se == v[j].fi){
							present = true;
							break;
						}
					}
					if(present) break;
					
				}
				

        if(present) 
            cout << "2" << endl;
        else 
            cout << "3" << endl;
    }
    return 0;
}
