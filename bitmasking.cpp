#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int n, vector<int>& nums, int target) {
    // Total number of subsets is 2^n
    int totalSubsets = 1 << n; // 2^n

    // Iterate through all possible subsets
    for (int mask = 0; mask < totalSubsets; mask++) {
        int sum = 0;

        // Calculate the sum of the current subset
        for (int i = 0; i < n; i++) {
            // Check if the i-th element is included in the subset
            if (mask & (1 << i)) {
                sum += nums[i];
            }
        }

        // Check if the current subset's sum is equal to the target
        if (sum == target) {
            return true; // Subset found
        }
    }

    return false; // No subset found with sum equal to target
}

int main() {
    int n, s;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the target sum: ";
    cin >> s;

    if (subsetSum(n, nums, s)) {
        cout << "YES, there is a subset with the sum equal to " << s << endl;
    } else {
        cout << "NO, there is no subset with the sum equal to " << s << endl;
    }

    return 0;
}
