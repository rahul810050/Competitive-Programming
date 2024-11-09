

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long power_mod(long long a, long long b, long long m) {
    long long result = 1;
    a = a % m;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b = b / 2;
    }
    return result;
}


int nim_sum(const vector<int>& piles) {
    int result = 0;
    for (int pile : piles) {
        result ^= pile;
    }
    return result;
}

void solve() {
    int N, D;
    cin >> N >> D;
    
    vector<int> piles(N);
    for (int i = 0; i < N; i++) {
        cin >> piles[i];
    }
    
    int nimSum = nim_sum(piles);
    

    long long p_Alice = (D * (D + 1) / 2) % MOD;
    long long p_Bob = (D * (D - 1) / 2) % MOD;
    
  
    long long D2 = (D * D) % MOD;
    

    long long D2_inv = power_mod(D2, MOD - 2, MOD);
    

    long long result;
    if (nimSum != 0) {

        result = (p_Alice * D2_inv) % MOD;
    } else {
    
        result = (p_Bob * D2_inv) % MOD;
    }
    
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}