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
#define M 1000000007

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
				int n, k;
        cin >> n >> k;
        
        priority_queue<ll, vector<ll>, greater<ll>> mHeap;
        
        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;
            mHeap.push(a);
        }
        
        while (k > 0) {
            ll mEle = mHeap.top();
            mHeap.pop();
            mEle *= 2;
            mHeap.push(mEle);
            k--;
        }
        
        ll sum = 0;
        while (!mHeap.empty()) {
            sum = (sum + mHeap.top()) % M;
            mHeap.pop();
        }
        
        cout << sum << endl;
		}
		return 0;
}