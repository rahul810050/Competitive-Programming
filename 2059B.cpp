#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Since we need the minimum cost, we want the first few numbers in array b
    // to be 1, 2, 3, ... as long as possible
    // We can achieve this by carefully selecting the even-indexed subarrays
    
    // Number of even-indexed subarrays = k/2
    int evenCount = k/2;
    
    // For minimum cost, we want the first elements to be 1,2,3,...
    // So we need to find elements 1,2,3,... in the array and separate them
    int ans = 1;
    int curr = 1;  // current number we're looking for
    
    // For each position i in array a
    for(int i = 0; i < n && evenCount > 0; i++) {
        if(a[i] == curr) {
            curr++;  // we found the next number we need
            evenCount--;  // use one partition here
        }
    }
    
    // After this process, 'curr' will be the first missing number in sequence
    ans = curr;
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}