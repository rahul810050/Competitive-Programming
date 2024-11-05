#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Include this header for the reverse function

using namespace std;

int count_occurrences(const string& layer, const string& target) {
    string ext_layer = layer + layer.substr(0, target.length() - 1);
    int count = 0;
    for (int i = 0; i <= ext_layer.length() - target.length(); ++i) {
        if (ext_layer.substr(i, target.length()) == target) {
            count++;
        }
    }
    return count;
}

vector<string> extract_layers(int n, int m, const vector<string>& carpet) {
    vector<string> layers;
    int sr = 0, er = n - 1;
    int sc = 0, ec = m - 1;

    while (sr <= er && sc <= ec) {
        string cl;

        cl += carpet[sr].substr(sc, ec - sc + 1);

        for (int i = sr + 1; i <= er; ++i) {
            cl += carpet[i][ec];
        }

        if (sr < er) {
            string reversed_row = carpet[er].substr(sc, ec - sc + 1);
            reverse(reversed_row.begin(), reversed_row.end());
            cl += reversed_row;
        }

        if (sc < ec) {
            for (int i = er - 1; i > sr; --i) {
                cl += carpet[i][sc];
            }
        }

        layers.push_back(cl);

        sr++;
        er--;
        sc++;
        ec--;
    }

    return layers;
}

vector<int> count_1543(int t, const vector<pair<pair<int, int>, vector<string>>>& cases) {
    string target = "1543";
    vector<int> results;

    for (int i = 0; i < t; i++) {
        int n = cases[i].first.first;
        int m = cases[i].first.second;
        const vector<string>& carpet = cases[i].second;

        vector<string> layers = extract_layers(n, m, carpet);
        int total = 0;

        for (const string& l : layers) {
            total += count_occurrences(l, target);
        }

        results.push_back(total);
    }

    return results;
}

int main() {
    int t;
    cin >> t;
    vector<pair<pair<int, int>, vector<string>>> cases;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        vector<string> carpet(n);
        for (int j = 0; j < n; j++) {
            cin >> carpet[j];
        }
        cases.push_back({{n, m}, carpet});
    }

    vector<int> results = count_1543(t, cases);

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}def count_occurrences(layer, target):
    ext_layer = layer + layer[:len(target)-1]
    return sum(1 for i in range(len(ext_layer) - len(target) + 1) if ext_layer[i:i + len(target)] == target)

def extract_layers(n, m, carpet):
    layers = []
    sr, er = 0, n - 1
    sc, ec = 0, m - 1
    
    while sr <= er and sc <= ec:
        cl = []
        
        cl.extend(carpet[sr][sc:ec + 1])
        
        for i in range(sr + 1, er):
            cl.append(carpet[i][ec])
        
        if sr < er:
            cl.extend(carpet[er][sc:ec + 1][::-1])
        
        if sc < ec:
            for i in range(er - 1, sr, -1):
                cl.append(carpet[i][sc])
        
        layers.append(''.join(cl))
        
        sr += 1
        er -= 1
        sc += 1
        ec -= 1
    
    return layers

def count_1543(t, cases):
    target = "1543"
    results = []
    
    for i in range(t):
        n, m = cases[i][0]
        carpet = cases[i][1]
        
        layers = extract_layers(n, m, carpet)
        total = 0
        
        for l in layers:
            total += count_occurrences(l, target)
        
        results.append(total)
    
    return results

t = int(input())
cases = []
for _ in range(t):
    n, m = map(int, input().split())
    carpet = [input().strip() for _ in range(n)]
    cases.append(((n, m), carpet))

results = count_1543(t, cases)

for result in results:
    print(result)
