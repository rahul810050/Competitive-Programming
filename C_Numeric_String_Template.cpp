// coded by  cocane

#include <bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n-1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define allp(x) (x).begin(), (x).begin() + (x).size()/2, (x).rbegin()
#define pb push_back
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vi v(n);
        forn(i, n) cin >> v[i];

        int m;
        cin >> m;

        while (m--) {
            unordered_map<char, int> m_1;
            unordered_map<int, char> m_2;

            string s;
            cin >> s;

            if (s.length() != n) {
                cout << "NO" << endl;
                continue;
            }

            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (m_1.find(s[j]) == m_1.end() && m_2.find(v[j]) == m_2.end()) {
                    m_1[s[j]] = v[j];
                    m_2[v[j]] = s[j];
                } else if ((m_1.find(s[j]) != m_1.end() && m_1[s[j]] != v[j]) || 
                        (m_2.find(v[j]) != m_2.end() && m_2[v[j]] != s[j])) {
                    flag = false;
                    break;
                }
            }

            cout << (flag ? "YES" : "NO") << endl;
        }
    }
    return 0;
}
