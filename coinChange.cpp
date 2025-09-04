#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    const int INF = amount + 1;
    vector<int> dp(amount + 1, INF);
    dp[0] = 0; 
    for (int coin : coins) 
        for (int i = coin; i <= amount; i++) 
            dp[i] = min(dp[i], dp[i - coin] + 1);
    return dp[amount] == INF ? -1 : dp[amount];
}

int main() {
    int n, amount; cin>>n>>amount;
    vector<int> coins(n);
    for(auto &it: coins) cin>>it;
    cout << coinChange(coins, amount) << endl; 
    return 0;
}
