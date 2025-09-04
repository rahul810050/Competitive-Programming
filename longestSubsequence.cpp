#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> sub; 
    for (int x : nums) {
        auto it = lower_bound(sub.begin(), sub.end(), x);
        if (it == sub.end()) sub.push_back(x); 
        else *it = x; 
    }
    return sub.size();
}
int main() {
    int n; cin>>n;
    vector<int> nums(n);
    for(auto &it: nums) cin>>it;
    cout << lengthOfLIS(nums) << endl; 
    return 0;
}
