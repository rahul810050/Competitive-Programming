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
	    cin >> n;
	    
	    int a[n];
	    for (int i = 0; i < n; i++)
	    {
	      cin >> a[i];  
	    }
	    
	    vector<int> seq { 0 };
	    int cur = 0;
	    
	    for (int i = 0; i < n; i++)
	    {
	        if (a[i] == 0)
	        {
	           cur++;
	        }
	        else
	        {
	            if (cur > 0) {
	                seq.push_back(cur);
	            }
	            cur = 0;
	        }
	    }
	    
	    sort(seq.begin(), seq.end(), greater<int>());
	    
	    if (seq[0] > 0 && seq[0] % 2 == 1 && seq[1] < (seq[0] + 1)/2)
	    {
	        cout << "Yes" << endl;
	    }
	    else
	    {
	        cout << "No" << endl;
	    }
  }
  return 0;
}