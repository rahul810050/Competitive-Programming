// coded by Cocane
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define forn(i, n) for (int i = 1; i <= n; i++)


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
				int n, k;
				cin >> n >> k;
				vi v(n + 1); 

				if (k % 2 == 1) { 
						forn(i, n - 1) v[i] = n;
						
				} else { 
						forn(i, n - 1) v[i] = n - 1;
				}
				
				v[n-1] = n; 

				forn(i, n) cout << v[i] << " ";
				cout << endl;
		}

    return 0;
}
