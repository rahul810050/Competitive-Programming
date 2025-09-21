#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        long long arrowPos = points[0][1]; 

        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > arrowPos) {
                arrows++;
                arrowPos = points[i][1];
            }
        }

        return arrows;
    }
};

int main() {
    int n;
    cin >> n; 

    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];  
    }
    Solution sol;
    cout << "Minimum Arrow shots: "<<sol.findMinArrowShots(points) << endl;

    return 0;
}

// [[10,16],[2,8],[1,6],[7,12]]
// [[1,2],[3,4],[5,6],[7,8]]
// [[1,2],[2,3],[3,4],[4,5]]