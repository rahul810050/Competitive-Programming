#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long x, y, k;
        cin >> x >> y >> k;

        // Calculate the number of moves needed to cover x and y
        long long moves_x = (x + k - 1) / k; // Moves required to cover x
        long long moves_y = (y + k - 1) / k; // Moves required to cover y
        
        // Total moves needed to cover both dimensions
        // We need to account for the fact that we need to alternate directions
        // Total moves = moves_x + moves_y + 1 - (if total number of moves is greater than 0)
        // This is because after finishing the x direction, we need to move in the y direction.
        long long total_moves = max(moves_x, moves_y) + max(moves_x, moves_y) - 1;
        
        cout << total_moves << endl;
    }

    return 0;
}
