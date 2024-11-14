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


bool canEat(int N, int k) {
    unordered_set<int> poss_slice = {0}; 

    for (int i = 0; i < N; ++i) {
        unordered_set<int> n_slice;
        
        for (int it : poss_slice) {
            n_slice.insert(it + 10);
            n_slice.insert(it + 11);
            n_slice.insert(it + 12);
        }

        poss_slice = n_slice;
    }

    return poss_slice.count(k) > 0;
}

int main(){
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		int t;
		cin>>t;
		while(t--){
				int n, k;
        cin >> n >> k;
        yn(canEat(n,k));
		}
		return 0;
}