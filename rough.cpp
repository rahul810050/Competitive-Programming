// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     long solve(int A, vector<int> &B, vector<int> &C) {
//         int n = A;
//         vector<int> f, g;
//         for (int i = 0; i < n; ++i) {
//             if (B[i] <= C[i]) f.push_back(i);
//             else g.push_back(i);
//         }
//         sort(f.begin(), f.end(), [&](int i, int j){ return B[i] < B[j]; });
//         sort(g.begin(), g.end(), [&](int i, int j){ return C[i] > C[j]; });
//         long t1 = 0, t2 = 0;
//         for (int i : f) {
//             t1 += B[i];
//             t2 = max(t2, t1) + C[i];
//         }
//         for (int i : g) {
//             t1 += B[i];
//             t2 = max(t2, t1) + C[i];
//         }
//         return t2;
//     }
// };

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int a;
//     cin >> a;
//     vector<int> b(a), c(a);
//     for (int i = 0; i < a; ++i) cin >> b[i];
//     for (int i = 0; i < a; ++i) cin >> c[i];
//     Solution sol;
//     cout << sol.solve(a, b, c);
//     return 0;
// }





// B



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddition(vector<int> &A, int B) {
        long long m = 1;
        int i = 0, n = A.size(), c = 0;
        while (m <= B) {
            if (i < n && A[i] <= m) {
                m += A[i++];
            } else {
                m += m;
                c++;
            }
        }
        return c;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, B;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    cin >> B;
    Solution s;
    cout << s.minAddition(A, B);
    return 0;
}
