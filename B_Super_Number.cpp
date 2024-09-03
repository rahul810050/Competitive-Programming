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
#define out(ans) cout<<ans<<endl
#define yn(a) cout<< (a ? "YES": "NO") <<endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

bool isPerfectSquare(ll num){
	int root = sqrt(num);
	return root * root == num;
}


int main(){
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		int t;
		cin>>t;
		while(t--){
				ll n, k;
        cin >> n >> k;
        
        vi super(n);  
        for (ll i = 0; i < n; i++) {
            ll ai;
            cin >> ai;
            super[i] = isPerfectSquare(ai) ? 1 : 0;
        }

        unordered_map<int, int> preCount; 
        preCount[0] = 1; 
        
        int curr = 0;
        ll superSub = 0;
        
        for (ll i = 0; i < n; i++) {
            curr += super[i];
            
            if (preCount.find(curr - k) != preCount.end()) {
                superSub += preCount[curr - k];
            }
            
            preCount[curr]++;
        }
        
        cout << superSub << endl;
		}
		return 0;
}