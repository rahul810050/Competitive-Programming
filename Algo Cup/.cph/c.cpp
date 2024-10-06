// coded by Cocane

#include <bits/stdc++.h>

#define ll long long
#define loop(i, n) for(int i = 0; i < n; i++)
#define loop1(i, n) for(int i = 1; i <= n; i++)
#define loopRev(i, n) for(int i = n-1; i >= 0; i--)
#define p1 first
#define p2 second
#define allElements(x) (x).begin(), (x).end()
#define halfElements(x) (x).begin(), (x).begin() + (x).size() / 2, (x).rbegin()
#define addElement push_back
#define removeElement pop_back
#define readElements(a) for(auto &elem: a) cin >> elem
#define print(ans) cout << ans << endl
#define isYes(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> intVector;
typedef vector<ll> longLongVector;
typedef double decimal;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    string commands;
    cin >> commands;

    map<int, set<pair<int, int>>> sumMap;
    map<int, set<pair<int, int>>> diffMap;
    vector<pair<int, int>> coordinates(N);

    loop(index, N) {
        int a, b;
        cin >> a >> b;
        coordinates[index] = {a, b};
        sumMap[a + b].insert({a, b});
        diffMap[a - b].insert({a, b});
    }

    int currentX = coordinates[0].p1;
    int currentY = coordinates[0].p2;

    sumMap[currentX + currentY].erase({currentX, currentY});
    if (sumMap[currentX + currentY].empty()) sumMap.erase(currentX + currentY);
    diffMap[currentX - currentY].erase({currentX, currentY});
    if (diffMap[currentX - currentY].empty()) diffMap.erase(currentX - currentY);

    for (char command : commands) {
        pair<int, int> nextPosition = {currentX, currentY};
        bool found = false;

        if (command == 'A') {
            auto iterator = diffMap[currentX - currentY].upper_bound({currentX, currentY});
            if (iterator != diffMap[currentX - currentY].end()) {
                nextPosition = *iterator;
                found = true;
            }
        } else if (command == 'B') {
            auto iterator = sumMap[currentX + currentY].upper_bound({currentX, currentY});
            if (iterator != sumMap[currentX + currentY].end()) {
                nextPosition = *iterator;
                found = true;
            }
        } else if (command == 'C') {
            auto iterator = sumMap[currentX + currentY].lower_bound({currentX, currentY});
            if (iterator != sumMap[currentX + currentY].begin()) {
                --iterator;
                nextPosition = *iterator;
                found = true;
            }
        } else if (command == 'D') {
            auto iterator = diffMap[currentX - currentY].lower_bound({currentX, currentY});
            if (iterator != diffMap[currentX - currentY].begin()) {
                --iterator;
                nextPosition = *iterator;
                found = true;
            }
        }

        if (found) {
            currentX = nextPosition.p1;
            currentY = nextPosition.p2;
            sumMap[currentX + currentY].erase({currentX, currentY});
            if (sumMap[currentX + currentY].empty()) sumMap.erase(currentX + currentY);
            diffMap[currentX - currentY].erase({currentX, currentY});
            if (diffMap[currentX - currentY].empty()) diffMap.erase(currentX - currentY);
        }
    }

    cout << currentX << " " << currentY << endl;
    return 0;
}
