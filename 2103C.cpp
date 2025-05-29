// coded by Cocane

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) {
        int n;
        ll k;
        cin >> n >> k;

        vector<ll> a(n+1), A(n+1), P(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            // transform
            A[i] = (a[i] <= k ? +1 : -1);
            P[i] = P[i-1] + A[i];
        }
        ll total = P[n];

        // prefix_min[i] = min( P[1..i] )
        vector<ll> prefix_min(n+1, LLONG_MAX);
        prefix_min[1] = P[1];
        for (int i = 2; i <= n; i++)
            prefix_min[i] = min(prefix_min[i-1], P[i]);

        // suffix_max[i] = max( P[i+1..n-1] ), only valid for i ≤ n-2
        vector<ll> suffix_max(n+1, LLONG_MIN),
                    suffix_min(n+1, LLONG_MAX);
        // we only need positions up to n-2
        ll cur_max = LLONG_MIN, cur_min = LLONG_MAX;
        for (int i = n-1; i >= 2; i--) {
            cur_max = max(cur_max, P[i]);
            cur_min = min(cur_min, P[i]);
            suffix_max[i-1] = cur_max;  // so suffix_max[l] = max P[l+1..]
            suffix_min[i-1] = cur_min;
        }

        bool ok = false;

        // check (1) Left + Middle  and  (2) Left + Right
        for (int l = 1; l <= n-2 && !ok; l++){
            ll S1 = P[l];
            // left+middle: need S1≥1 and (some r>l) P[r]≥P[l]+1
            if (S1 >= 1 && suffix_max[l] >= S1 + 1) {
                ok = true;
                break;
            }
            // left+right: S1≥1 and (some r>l) P[r] ≤ total-1
            if (S1 >= 1 && suffix_min[l] <= total - 1) {
                ok = true;
                break;
            }
        }

        // check (3) Middle + Right
        for (int r = 2; r <= n-1 && !ok; r++){
            ll Sr = P[r];
            // need Sr ≤ total-1  &&  prefix_min[r-1] ≤ Sr-1
            if (Sr <= total - 1 && prefix_min[r-1] <= Sr - 1) {
                ok = true;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
