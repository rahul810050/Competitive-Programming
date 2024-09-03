#include <bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define all(x) (x).begin(),(x).end()

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vi v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        ll product = 1;
        bool overflow = false;

        forn(i,n) product *= v[i];

				if(product > 2023) cout<<"NO"<<endl;
				else if (2023 % product ==0){
					cout<<"YES"<<endl;
					cout<<2023 / product;
					forn(i , k-1) cout<<" 1";
					cout<<endl;
				}
				else cout<<"NO"<<endl;

        
    }
    return 0;
}
