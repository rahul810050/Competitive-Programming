#include <bits/stdc++.h>
using namespace std;

#define ll long long

// Function to check if a point is inside a circle
bool isInsideCircle(int x, int y, int cx, int cy, int r) {
    return (x - cx) * (x - cx) + (y - cy) * (y - cy) < r * r;
}

// Function to determine if reaching the target is possible
bool canReach(int X, int Y, vector<tuple<int, int, int>>& circles) {
    // Directions for movement: down, right, up, left
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    // BFS initialization
    queue<pair<int, int>> q;
    q.push({0, Y});  // Start at the top-left corner
    set<pair<int, int>> visited;
    visited.insert({0, Y});

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first; // Access the x-coordinate
        int y = current.second; // Access the y-coordinate

        // Check if reached the bottom-right corner
        if (x == X && y == 0) return true;

        // Explore all 4 directions
        for (auto direction : directions) {
            int nx = x + direction.first;
            int ny = y + direction.second;

            // Check bounds
            if (nx < 0 || nx > X || ny < 0 || ny > Y) continue;

            // Check if inside any circle
            bool insideCircle = false;
            for (auto circle : circles) {
                int cx = get<0>(circle); // Access circle center x
                int cy = get<1>(circle); // Access circle center y
                int r = get<2>(circle); // Access circle radius
                if (isInsideCircle(nx, ny, cx, cy, r)) {
                    insideCircle = true;
                    break;
                }
            }
            if (!insideCircle && visited.find({nx, ny}) == visited.end()) {
                visited.insert({nx, ny});
                q.push({nx, ny});
            }
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int X, Y;
        cin >> X >> Y;
        int N;
        cin >> N;
        vector<tuple<int, int, int>> circles(N);
        for (int i = 0; i < N; ++i) {
            int cx, cy, r;
            cin >> cx >> cy >> r;
            circles[i] = {cx, cy, r};
        }
        if (canReach(X, Y, circles)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
