#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, c;
int x[N];

bool aggressiveCow(int dis) {
    int last_position = x[0];
    int cows_count = 1;

    for (int i = 1; i < n; i++) {  
        if (x[i] - last_position >= dis) {
            cows_count++;
            last_position = x[i];
        }
        if (cows_count >= c) return true;
    }
    return false;
}

int main() {
    int t; 
    cin >> t;

    while (t--) {
        cin >> n >> c;

        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }

        sort(x, x + n);  

        int lo = 1, hi = x[n-1] - x[0], mid;
        int ans = 0;

        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (aggressiveCow(mid)) {
                ans = mid;  
                lo = mid + 1; 
            } else {
                hi = mid - 1; 
            }
        }

        cout << ans << endl;
    }

    return 0;
}
