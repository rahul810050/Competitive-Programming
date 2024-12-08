#include <bits/stdc++.h>

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)
#define read(a) for (auto &i : a) cin >> i
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vi a(n);
        read(a);

				int f = 0;


        for (int i = 0; i < n; i++) {
						int ct = 0;
            for (int j = 0; j < n; j++) {
              if(j != i){
								int x = abs(a[i]- a[j]);
								if(x % k != 0) ct++;
							}
            }
						if(ct == n-1){
							cout<<"YES"<<endl;
							cout<<i+1<<endl;
							f = 1;
							break;
						}
            
        }

				if(f == 0) cout<<"NO"<<endl;

    }

    return 0;
}
