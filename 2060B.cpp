// coded by Cocane

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> cards(n); // Cards for each cow
        forn(i, n) {
            cards[i].resize(m);
            forn(j, m) cin >> cards[i][j];
            sort(all(cards[i])); // Sort cards for each cow
        }

        vector<int> order(n);
        iota(all(order), 1);

        sort(all(order), [&](int i, int j) {
            return cards[i - 1][0] < cards[j - 1][0];
        }); 

        int tpCard = -1; 
        bool poss = true;

        for (int rnd = 0; rnd < m && poss; rnd++) {
            for (int i : order) {
                auto &deck = cards[i - 1];
                if (deck.empty() || deck[0] <= tpCard) {
                    poss = false; 
                    break;
                }
                tpCard = deck[0]; 
                deck.erase(deck.begin()); 
            }
        }

        if (poss) {
            for (int i : order) cout << i << " ";
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
