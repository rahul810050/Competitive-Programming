// coded by Cocane
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define all(v) v.begin(), v.end()

void solve() {
    int n;
    cin >> n;
    int size = 2 * n;
    vi b(size);
    for (int i = 0; i < size; i++) cin >> b[i];

    sort(all(b));  

    vi oddGroup(b.begin(), b.begin() + n); 
    vi evenGroup(b.begin() + n, b.end());  

    ll sumEven = accumulate(all(evenGroup), 0LL);
    ll sumOdd = accumulate(all(oddGroup), 0LL);

    ll a1 = sumEven - sumOdd;

    if (a1 > 0 && find(all(b), a1) == b.end()) {
        cout << a1 << " ";
        for (int i = 0; i < n; i++) cout << evenGroup[i] << " " << oddGroup[i] << " ";
        cout << endl;
        return;
    }

    ll maxElement = b.back();
    b.pop_back();  

    oddGroup.assign(b.begin(), b.begin() + n);
    evenGroup.assign(b.begin() + n, b.end());

    sumEven = accumulate(all(evenGroup), 0LL);
    sumOdd = accumulate(all(oddGroup), 0LL);
    
    ll xCandidate = maxElement - (sumEven - sumOdd);
    
    if (xCandidate > 0) {
        cout << maxElement << " ";
        for (int i = 0; i < n - 1; i++) cout << evenGroup[i] << " " << oddGroup[i] << " ";
        cout << xCandidate << endl;
        return;
    }

    cout << "-1\n"; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
