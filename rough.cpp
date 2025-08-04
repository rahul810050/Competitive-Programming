// // #include <bits/stdc++.h>
// // using namespace std;

// // class Solution {
// // public:
// //     long solve(int A, vector<int> &B, vector<int> &C) {
// //         int n = A;
// //         vector<int> f, g;
// //         for (int i = 0; i < n; ++i) {
// //             if (B[i] <= C[i]) f.push_back(i);
// //             else g.push_back(i);
// //         }
// //         sort(f.begin(), f.end(), [&](int i, int j){ return B[i] < B[j]; });
// //         sort(g.begin(), g.end(), [&](int i, int j){ return C[i] > C[j]; });
// //         long t1 = 0, t2 = 0;
// //         for (int i : f) {
// //             t1 += B[i];
// //             t2 = max(t2, t1) + C[i];
// //         }
// //         for (int i : g) {
// //             t1 += B[i];
// //             t2 = max(t2, t1) + C[i];
// //         }
// //         return t2;
// //     }
// // };

// // int main() {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     int a;
// //     cin >> a;
// //     vector<int> b(a), c(a);
// //     for (int i = 0; i < a; ++i) cin >> b[i];
// //     for (int i = 0; i < a; ++i) cin >> c[i];
// //     Solution sol;
// //     cout << sol.solve(a, b, c);
// //     return 0;
// // }





// // B



// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int minAddition(vector<int> &A, int B) {
//         long long m = 1;
//         int i = 0, n = A.size(), c = 0;
//         while (m <= B) {
//             if (i < n && A[i] <= m) {
//                 m += A[i++];
//             } else {
//                 m += m;
//                 c++;
//             }
//         }
//         return c;
//     }
// };

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, B;
//     cin >> n;
//     vector<int> A(n);
//     for (int i = 0; i < n; ++i) cin >> A[i];
//     cin >> B;
//     Solution s;
//     cout << s.minAddition(A, B);
//     return 0;
// }

        

// vector<pair<int,int>> g[n+1];
//         for(int i = 0; i < m; i++){
//             g[edges[i][0]].push_back({edges[i][1], edges[i][2]});
//             g[edges[i][1]].push_back({edges[i][0], edges[i][2]});
//         }

//         vector<int> parent(n+1);
//         vector<int> dist(n+1, 1e9+10);
//         for(int i = 1; i <= n; i++) parent[i] = i;

//         set<pair<int,int>> st;
//         st.insert({0, 1});
//         dist[1] = 0;

//         while(!st.empty()){
//             auto curr = *st.begin();
//             st.erase(st.begin());
//             int v = curr.second;
//             int v_dist = curr.first;

//             for(auto child : g[v]){
//                 int child_v = child.first;
//                 int wt = child.second;
//                 if(dist[v] + wt < dist[child_v]){
//                     st.erase({dist[child_v], child_v}); // safe even if it doesn't exist
//                     dist[child_v] = dist[v] + wt;
//                     parent[child_v] = v;
//                     st.insert({dist[child_v], child_v});
//                 }
//             }
//         }

//         if(dist[n] == 1e9+10) return {-1};

//         vector<int> path;
//         int curr = n;
//         while(parent[curr] != curr){
//             path.push_back(curr);
//             curr = parent[curr];
//         }
//         path.push_back(1);
//         reverse(path.begin(), path.end());

//         return path;