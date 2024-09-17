#include <bits/stdc++.h>
using namespace std;

// Correct partition function
int partition(vector<int> &v, int l, int r) {
    int pivot = v[r];
    int i = l - 1; // Index of the smaller element

    // Traverse through all elements
    for (int j = l; j < r; j++) {
        if (v[j] < pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }

    // Place pivot in the correct position
    swap(v[i + 1], v[r]);

    // Return the index of the pivot element
    return i + 1;
}

// Correct QuickSort function
void QuickSort(vector<int> &v, int l, int r) {
    if (l < r) {
        // Get the pivot index
        int pi = partition(v, l, r);

        // Recursively sort elements before and after partition
        QuickSort(v, l, pi - 1);
        QuickSort(v, pi + 1, r);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    QuickSort(v, 0, n - 1);

    for (const auto &it : v) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
