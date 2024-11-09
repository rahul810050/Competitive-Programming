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

int func(int n) 
{
    for (int i = n / 2; i >= 1; --i) 
    {
        if (n % i == 0) 
        return i;
    }
    return 1; 
}

int solve(int h) 
{
    int cnt = 0;
    while (h > 1) {
        h = func(h);
        cnt++;
    }
    return cnt;
}


int main(){
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		int t;
		cin>>t;
		while(t--){
				int H, K;
        cin >> H >> K;
        
        int ans = 0;
        for (int i = 1; i <= K; ++i) 
        {
            int ini = H * i;
            int b = solve(ini);
            ans = max(ans, b);
        }
        
        out(ans);
		}
		return 0;
}