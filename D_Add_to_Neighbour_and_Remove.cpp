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


int main(){
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		int t;
		cin>>t;
		while(t--){

			int n;cin>>n;
			vi a(n);
			ll sum = 0;
			for (int i = 0; i < n; i++)
			{
				cin>>a[i];
				sum += a[i];
			}
			
				for (int i = n; i >= 1; i--) {
    			if (sum % i == 0) {
					ll needSum = sum / i;
					ll curSum = 0;
					bool ok = true;
					for (int j = 0; j < n; j++) {
						curSum += a[j];
						if (curSum > needSum) {
							ok = false;
							break;
						} else if (curSum == needSum) {
							curSum = 0;
						}
      }

      if (ok) {
        cout << n - i << endl;
        break;
      }
    }
  }
		}
		return 0;
}