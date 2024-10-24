#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        // Store original array and sorted array
        vector<int> sortedA = A;
        sort(sortedA.begin(), sortedA.end());

        // Check if it's possible to make the array sorted
        if (A == sortedA) {
            cout << "0\n"; // Already sorted
            continue;
        }

        vector<pair<int, int>> operations;

        // Attempt to sort the array
        while (true) {
            bool madeChange = false;

            for (int i = 0; i < N; i++) {
                for (int j = i + 2; j < N; j += 2) { // j must be odd (i + 2)
                    // Extract the subarray
                    vector<int> subarray(A.begin() + i, A.begin() + j + 1);
                    sort(subarray.begin(), subarray.end());
                    int medianIndex = subarray.size() / 2; // Middle index for odd length
                    int median = subarray[medianIndex];

                    // Find the leftmost occurrence of the median in the subarray
                    int leftIndex = -1;
                    for (int k = i; k <= j; k++) {
                        if (A[k] == median) {
                            leftIndex = k;
                            break;
                        }
                    }

                    if (leftIndex != -1) {
                        // Perform the operation
                        operations.emplace_back(leftIndex + 1, leftIndex + 1); // Store 1-based index
                        A[leftIndex] = -1; // Mark as deleted
                        madeChange = true;
                    }
                }
            }

            // Remove all -1 values (deleted elements)
            vector<int> newA;
            for (int i = 0; i < N; i++) {
                if (A[i] != -1) {
                    newA.push_back(A[i]);
                }
            }
            A = newA;
            N = A.size(); // Update size

            if (!madeChange) {
                break; // No more changes possible
            }
        }

        // Check if sorted
        if (A == sortedA) {
            cout << operations.size() << "\n";
            for (const auto& op : operations) {
                cout << op.first << " " << op.second << "\n";
            }
        } else {
            cout << "-1\n"; // Not possible to sort
        }
    }

    return 0;
}
