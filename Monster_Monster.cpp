// coded by Cocane

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define read(a) for (auto &i : a) cin >> i

typedef vector<int> vi;

void solvve() {
    int n, x;
    cin >> n >> x;
    vi h(n);
    read(h);

    int mx = *max_element(all(h));
		if(mx > x){
			cout<<mx<<endl;
			return;
		}

    int mn = *min_element(all(h));
    cout << ((n - 1) * 10) + mn << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solvve();
    }
    return 0;
}
