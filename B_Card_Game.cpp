#include <bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n-1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define out(ans) cout<<ans<<endl
#define yn(a) cout<< (a ? "YES": "NO") <<endl

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        vector<pair<int, int>> su_cards = {{a1, a2}, {a2, a1}};
        vector<pair<int, int>> sl_cards = {{b1, b2}, {b2, b1}};

        int winner = 0;

        for(auto su_flip : su_cards) {
            for(auto sl_flip : sl_cards) {
                int su_score = 0, sl_score = 0;

                if(su_flip.fi > sl_flip.fi) su_score++;
                else if(su_flip.fi < sl_flip.fi) sl_score++;

                if(su_flip.se > sl_flip.se) su_score++;
                else if(su_flip.se < sl_flip.se) sl_score++;

                if(su_score > sl_score) winner++;
            }
        }

        out(winner);
    }

    return 0;
}
