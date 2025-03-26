// Developed by Cocane

#include <bits/stdc++.h>

using namespace std;

int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return (b == 0) ? 0 : (a / b); }

void pTest() {
    int t;
    cin >> t;

    while (t--) {
        int arrSz;
        cin >> arrSz;

        vector<int> numrs(arrSz);
        int mx = 0;

        for (int i = 0; i < arrSz; i++) {
            cin >> numrs[i];
            mx = max(mx, numrs[i]);
        }

        vector<int> f(add(mx, 1), 0);

        for (int i = 0; i < arrSz; i++) {
            f[numrs[i]]++;
        }

        int odCt = 0, z0Ct = 0;
        int initialZeros = f[0];

        for (int v = 1; v <= mx; v++) {
            if (f[v] % 2 == 1)
                odCt = add(odCt, 1);
            z0Ct = add(z0Ct, divide(f[v], 2));
        }

        int toZ0s = add(initialZeros, z0Ct);
        int remZ0 = (toZ0s > 0) ? 1 : 0;

        int ans = add(odCt, remZ0);
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pTest();

    return 0;
}
