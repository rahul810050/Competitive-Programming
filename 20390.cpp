#include <iostream>
#include <vector>
using namespace std;

vector<int> constructSequence(int n) {
    vector<int> result;
    int start = 2; // Start with 2 as it satisfies constraints
    for (int i = 1; i <= n; ++i) {
        result.push_back(start);
        start += i + 1; // Increment to ensure uniqueness and increasing order
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> sequence = constructSequence(n);
        for (int num : sequence) {
            cout << num << " ";	
        }
        cout << endl;
    }
    return 0;
}
