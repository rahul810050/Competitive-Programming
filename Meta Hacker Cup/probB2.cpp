#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
const ll MOD = 1000000007LL;

ull modmul64(ull a, ull b, ull mod) {
    __uint128_t res = (__uint128_t)a * b;
    res %= mod;
    return (ull)res;
}
ull modpow64(ull a, ull e, ull mod) {
    ull r = 1 % mod;
    while (e) {
        if (e & 1) r = modmul64(r, a, mod);
        a = modmul64(a, a, mod);
        e >>= 1;
    }
    return r;
}

bool isPrime64(ull n) {
    if (n < 2) return false;
    for (ull p : {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL})
        if (n % p == 0) return n == p;
    ull d = n - 1, s = 0;
    while ((d & 1) == 0) { d >>= 1; s++; }
    ull bases[] = {2ULL,325ULL,9375ULL,28178ULL,450775ULL,9780504ULL,1795265022ULL};
    for (ull a : bases) {
        if (a % n == 0) continue;
        ull x = modpow64(a % n, d, n);
        if (x == 1 || x == n - 1) continue;
        bool comp = true;
        for (ull r = 1; r < s; ++r) {
            x = modmul64(x, x, n);
            if (x == n - 1) { comp = false; break; }
        }
        if (comp) return false;
    }
    return true;
}

mt19937_64 rng64(chrono::high_resolution_clock::now().time_since_epoch().count());
ull pollard_f(ull x, ull c, ull mod) { return (modmul64(x, x, mod) + c) % mod; }
ull pollard_rho(ull n) {
    if (n % 2ULL == 0ULL) return 2ULL;
    if (n % 3ULL == 0ULL) return 3ULL;
    ull c = uniform_int_distribution<ull>(1, n - 1)(rng64);
    ull x = uniform_int_distribution<ull>(2, n - 2)(rng64);
    ull y = x, d = 1;
    while (d == 1) {
        x = pollard_f(x, c, n);
        y = pollard_f(pollard_f(y, c, n), c, n);
        ull diff = x > y ? x - y : y - x;
        d = std::gcd(diff, n);
        if (d == n) return pollard_rho(n);
    }
    return d;
}
void factor_rec(ull n, map<ull, int> &mp) {
    if (n == 1) return;
    if (isPrime64(n)) { mp[n]++; return; }
    ull d = pollard_rho(n);
    factor_rec(d, mp);
    factor_rec(n / d, mp);
}

ll modpow(ll a, ll e) {
    ll r = 1 % MOD;
    ll base = (a % MOD + MOD) % MOD;
    while (e) {
        if (e & 1) r = (__int128)r * base % MOD;
        base = (__int128)base * base % MOD;
        e >>= 1;
    }
    return r;
}
ll inv(ll x) { return modpow(x, MOD - 2); }

int MAXE = 70;
vector<ll> fact, invfact;
void precompute_factorials() {
    fact.assign(MAXE + 1, 1);
    for (int i = 1; i <= MAXE; i++) fact[i] = fact[i - 1] * i % MOD;
    invfact.assign(MAXE + 1, 1);
    invfact[MAXE] = inv(fact[MAXE]);
    for (int i = MAXE - 1; i >= 0; i--) invfact[i] = invfact[i + 1] * (i + 1) % MOD;
}

ll comb_N_e(unsigned long long N_large, int e) {
    if (e == 0) return 1;
    ll numer = 1;
    ll Nmod = (ll)(N_large % (unsigned long long)MOD);
    for (int j = 0; j < e; ++j) {
        ll term = (Nmod + j) % MOD;
        numer = (__int128)numer * term % MOD;
    }
    ll res = numer * invfact[e] % MOD;
    return res;
}
ll compute_g_from_exponents(unsigned long long N_large, const vector<int> &exps) {
    ll res = 1;
    for (int e : exps) {
        ll c = comb_N_e(N_large, e);
        res = (__int128)res * c % MOD;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    precompute_factorials();
    int T;
    if (!(cin >> T)) return 0;
    for (int tc = 1; tc <= T; tc++) {
        unsigned long long N, A, B;
        cin >> N >> A >> B;
        map<ull, int> fmp;
        factor_rec(B, fmp);
        vector<ull> primes;
        vector<int> exps_all;
        for (auto &pr : fmp) {
            primes.push_back(pr.first);
            exps_all.push_back(pr.second);
        }
        int M = primes.size();
        vector<pair<unsigned long long, vector<int>>> divisors;
        vector<int> cur(M, 0);
        function<void(int, unsigned long long)> gen = [&](int idx, unsigned long long val) {
            if (idx == M) {
                divisors.emplace_back(val, cur);
                return;
            }
            unsigned long long p = primes[idx], v = 1;
            for (int e = 0; e <= exps_all[idx]; ++e) {
                cur[idx] = e;
                gen(idx + 1, val * v);
                v *= p;
            }
            cur[idx] = 0;
        };
        gen(0, 1ULL);
        ll ans = 0;
        for (auto &dv : divisors) {
            unsigned long long dval = dv.first;
            if (dval > A) continue;
            vector<int> e_d = dv.second, e_q(M);
            for (int i = 0; i < M; i++) e_q[i] = exps_all[i] - e_d[i];
            ll g_d = compute_g_from_exponents(N, e_d);
            ll g_q = compute_g_from_exponents(N, e_q);
            ll add = (__int128)g_d * g_q % MOD;
            ans += add;
            if (ans >= MOD) ans -= MOD;
        }
        cout << "Case #" << tc << ": " << ans << "\n";
    }
    return 0;
}
