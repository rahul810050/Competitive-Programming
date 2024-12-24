#include <iostream>
#include <vector>
#include <set>

using namespace std;

int calculateMEX(const set<int> &values) {
    int mex = 0;
    while (values.find(mex) != values.end()) {
        mex++;
    }
    return mex;
}

vector<int> assignValues(int size, int x, int y) {
    vector<int> result(size, -1);
    vector<set<int>> neighbors(size);

    for (int i = 0; i < size; i++) {
        neighbors[i].insert((i + 1) % size);
        neighbors[i].insert((i - 1 + size) % size);
    }

    x--, y--;
    neighbors[x].insert(y);
    neighbors[y].insert(x);

    for (int i = 0; i < size; i++) {
        set<int> neighborValues;
        for (int neighbor : neighbors[i]) {
            if (result[neighbor] != -1) {
                neighborValues.insert(result[neighbor]);
            }
        }
        result[i] = calculateMEX(neighborValues);
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> values = assignValues(n, x, y);

        for (int value : values) cout << value << " ";
        
        cout << endl;
    }

    return 0;
}
