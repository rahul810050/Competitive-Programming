// coded by Cocane

#include<bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define out(ans) cout<<ans<<endl

using namespace std;

typedef vector<int> vi;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vi v(n);

        for(auto &it : v) cin >> it;

        int mx_odd = 0;
				int ct_odd = 0;

				for (int i = 0; i < n; i+=2)
				{
					mx_odd = max(mx_odd, v[i]);
					ct_odd++;
				}

        int mx_even = 0;
				int ct_even = 0;

				for (int i = 1; i < n; i+=2)
				{
					mx_even = max(mx_even, v[i]);
					ct_even++;
				}

				int score_odd = mx_odd + ct_odd;
				int score_even = mx_even + ct_even;

				cout<<max(score_odd , score_even)<<endl;
				

        
    }
    return 0;
}
