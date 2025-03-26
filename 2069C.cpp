// coded by Cocane

#include<bits/stdc++.h>

// #define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n-1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define allp(x) (x).begin(), (x).begin() + (x).size()/2, (x).rbegin()
#define pb push_back
#define ppb pop_back
#define read(a) for(auto &i: a) cin >> i
#define out(ans) cout<<ans<<endl
#define yn(a) cout<< (a ? "YES": "NO") <<endl

using namespace std;

// typedef vector<int> vi;
// typedef vector<ll> vll;
typedef double dl;

#define MODULO 998244353
#define LIMIT 200005

typedef long long ll;
vector<ll> PT(LIMIT), inversePT(LIMIT);

ll MD(ll a, ll b) {
    return (a + b) % MODULO;
}

ll MM(ll a, ll b) {
    return (a * b) % MODULO;
}

void CPower() {
    PT[0] = 1;
    for (int i = 1; i < LIMIT; i++) {
        PT[i] = MM(PT[i - 1], 2LL);
    }

    ll iot = 499122177;
    inversePT[0] = 1;
    for (int i = 1; i < LIMIT; i++) {
        inversePT[i] = MM(inversePT[i - 1], iot);
    }
}

ll cContributions(int countTwos, ll sumOfOnes, int onesSeen) {
    ll contribution = MM(PT[countTwos], sumOfOnes);
    contribution = MD(contribution, -onesSeen + MODULO); // Ensure positive mod
    return contribution;
}

ll evalSeq(int length, vector<int>& sec) {
    ll totalScore = 0, sumOfOnes = 0;
    int oneEn = 0, twoEn = 0;

    for (int i = 0; i < length; i++) {
        if (sec[i] == 1) {
            sumOfOnes = MD(sumOfOnes, inversePT[twoEn]);
            oneEn++;
        } 
        else if (sec[i] == 2) {
            twoEn++;
        } 
        else if (sec[i] == 3) {
            totalScore = MD(totalScore, cContributions(twoEn, sumOfOnes, oneEn));
        }
    }
    return totalScore;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    CPower();

    int testCases;
    cin >> testCases;
    while (testCases--) {
        int secL;
        cin >> secL;
        vector<int> sec(secL);
        for (int &value : sec) cin >> value;

        cout << evalSeq(secL, sec) << endl;
    }

    return 0;
}