#include <bits/stdc++.h>
using namespace std;

int countRightTriangles(vector<pair<int, int>>& points) {
    unordered_map<int, int> y0_count, y1_count;
    
    // Count x-coordinates for y=0 and y=1
    for (const auto& p : points) {
        if (p.second == 0) {
            y0_count[p.first]++;
        } else {
            y1_count[p.first]++;
        }
    }
    
    int count = 0;
    
    // Count the number of right triangles
    for (auto it1 = y0_count.begin(); it1 != y0_count.end(); ++it1) {
        int x1 = it1->first;
        int freq1 = it1->second;
        
        for (auto it2 = y1_count.begin(); it2 != y1_count.end(); ++it2) {
            int x2 = it2->first;
            int freq2 = it2->second;
            
            if (x1 != x2) {
                count += freq1 * freq2;
            }
        }
    }
    
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> points(n);
        for (int i = 0; i < n; ++i) {
            cin >> points[i].first >> points[i].second;
        }
        
        cout << countRightTriangles(points) << '\n';
    }

    return 0;
}
