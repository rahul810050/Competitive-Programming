// // coded by Cocane

// #include<bits/stdc++.h>

// #define ll long long
// #define forn(i, n) for(int i = 0; i < n; i++)
// #define for1(i, n) for(int i = 1; i <= n; i++)
// #define foru(i, n) for(int i = n-1; i >= 0; i--)
// #define fi first
// #define se second
// #define all(x) (x).begin(),(x).end()
// #define allp(x) (x).begin(), (x).begin() + (x).size()/2, (x).rbegin()
// #define pb push_back
// #define ppb pop_back
// #define read(a) for(auto &i: a) cin >> i
// #define out(ans) cout<<ans<<endl
// #define yn(a) cout<< (a ? "YES": "NO") <<endl

// using namespace std;

// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef double dl;


// const ll MOD = 1000000007;

// ll m_Exp(ll base, ll exp, ll mod) {
//     ll ans = 1;
//     while (exp > 0) {
//         if (exp % 2 == 1) {
//             ans = (ans * base) % mod;
//         }
//         base = (base * base) % mod;
//         exp /= 2;
//     }
//     return ans;
// }

// ll m_inver(ll a, ll mod) {
//     return m_Exp(a, mod - 2, mod);
// }

// ll mmL(ll a, ll b, ll mod) {
//     ll ans = 0;
//     while (b > 0) {
//         if (b % 2 == 1) {
//             ans = (ans + a) % mod;
//         }
//         a = (a + a) % mod;
//         b /= 2;
//     }
//     return ans;
// }

// map<ll, ll> p_fac(ll n) {
//     map<ll, ll> fac;
//     for (ll i = 2; i * i <= n; i++) {
//         while (n % i == 0) {
//             fac[i]++;
//             n /= i;
//         }
//     }
//     if (n > 1) {
//         fac[n] = 1;
//     }
//     return fac;
// }

// int main() {
//     ll A, B;
//     cin >> A >> B;

//     if (A == 1 || B == 0) {
//         cout << 1 << endl;
//         return 0;
//     }

//     map<ll, ll> fac = p_fac(A);

//     ll ans = 1;
//     for (auto it = fac.begin(); it != fac.end(); ++it) {
//         ll p = it->fi;
//         ll e = it->se;

//         ll exp = mmL(e, B, MOD - 1);

//         ll nume = m_Exp(p, exp + 1, MOD) - 1;
//         if (nume < 0) nume += MOD; 
//         ll deno = m_inver(p - 1, MOD);

//         ans = (ans * ((nume * deno) % MOD)) % MOD;
//     }

//     cout << ans << endl;
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back

vector<int> board;
vector<int> state;
int n;

bool dfs(int s, int m) {
    if (s < 1 || s > n) return false;
    if (s == m) return true;
    if (state[s] != 0) return state[s] == 2;

    state[s] = 1;
    int nextPos = s + board[s - 1];

    if (dfs(nextPos, m)) {
        state[s] = 2;
        return true;
    }

    state[s] = 1;
    return false;
}

int countWinningInstances() {
    int winningCount = 0;

    for (int m = 1; m <= n; m++) {
        fill(state.begin(), state.end(), 0);
        for (int s = 1; s <= n; s++) {
            if (dfs(s, m)) {
                winningCount++;
            }
        }
    }

    return winningCount;
}

int main() {
    cin >> n;
    board.resize(n);
    state.resize(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    int result = countWinningInstances();
    cout << result << endl;

    return 0;
}
