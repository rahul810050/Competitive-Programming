#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        string S;
        cin >> N >> S;

        int count1 = 0, count0 = 0;

        // Count the number of '1's and '0's
        for (char c : S) {
            if (c == '1') {
                count1++;
            } else {
                count0++;
            }
        }

        // Determine the minimum possible length of the string after operations
        int result;
        if (count1 % 2 == 0) {
            // Even number of '1's
            result = count0; // All '1's can be removed
        } else {
            // Odd number of '1's
            result = count0 + 1; // One '1' remains
        }

        cout << result << "\n";
    }

    return 0;
}
