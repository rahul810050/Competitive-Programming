#include<bits/stdc++.h>
using namespace std;
#define pb push_back

#define MAX_N 10000000

vector<bool> sie(MAX_N + 1, true);
vector<int> prime;

void allPrimes(int N) {
    sie[0] = sie[1] = false;
    for (int i = 2; i <= N; i++) {
        if (sie[i]) {
            prime.pb(i);
            for (int j = i * 2; j <= N; j += i) {
                sie[j] = false;
            }
        }
    }
}

int countSubstract(int N) {
    int count = 0;

    vector<int> primeUptoN;
    for (int p : prime) {
        if (p > N) break;
        primeUptoN.pb(p);
    }

    unordered_set<int> unique;

    for (int i = 1; i < primeUptoN.size(); i++) {
        for (int j = 0; j < i; j++) {
            int diff = primeUptoN[i] - primeUptoN[j];
            if (diff > N) break; 
            if (sie[diff]) {
                unique.insert(diff);
            }
        }
    }

    return unique.size();
}

void solve() {
    int n;
    cin >> n;

    int ans = countSubstract(n);
    cout << ans << endl; 
}

void main_() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    allPrimes(MAX_N); 

    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}

int main(){
    main_();
}
