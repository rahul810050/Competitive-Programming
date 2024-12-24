#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        ll n, m, k;
        cin >> n >> m >> k;
        
        // Count how many numbers are NOT in array b
        int missing_count = n;
        vector<bool> present(n + 1, false);
        vector<int> a(m);
        
        // Read array a
        for(int i = 0; i < m; i++) {
            cin >> a[i];
        }
        
        // Mark numbers present in array b and count them
        for(int i = 0; i < k; i++) {
            int x;
            cin >> x;
            if(!present[x]) {
                present[x] = true;
                missing_count--;
            }
        }
        
        string result;
        result.reserve(m);
        
        // Key optimization: We know that for result to be '1',
        // all numbers except a[i] must be in array b
        // This means missing_count must be 0 or 1
        if(missing_count > 1) {
            // If more than one number is missing, all results must be '0'
            result = string(m, '0');
        } else {
            // If only 0 or 1 numbers are missing
            for(int i = 0; i < m; i++) {
                // If missing_count is 0, we need all numbers to be in b for '1'
                if(missing_count == 0) {
                    result += '1';
                }
                // If missing_count is 1, we need the missing number to be a[i] for '1'
                else if(missing_count == 1 && !present[a[i]]) {
                    result += '1';
                }
                else {
                    result += '0';
                }
            }
        }
        
        cout << result << '\n';
    }
    return 0;
}