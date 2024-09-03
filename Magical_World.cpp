#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int A, B, X;
        cin >> A >> B >> X;

        // Calculate the areas
        int square_area = X * X;
        int rectangle_area = A * B;

        // If the square area is already larger or equal, no cost is needed
        if (square_area >= rectangle_area) {
            cout << 0 << endl;
        } else {
            // Calculate minimum cost to reduce the rectangle area
            int cost_A = 0, cost_B = 0;

            // Reducing A to make rectangle_area <= square_area
            while ((A - cost_A) * B > square_area && A - cost_A > 0) {
                cost_A++;
            }

            // Reducing B to make rectangle_area <= square_area
            while (A * (B - cost_B) > square_area && B - cost_B > 0) {
                cost_B++;
            }

            // Output the minimum cost
            cout << min(cost_A, cost_B) << endl;
        }
    }
    return 0;
}
