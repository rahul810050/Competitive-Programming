// hamiltonian   cycle

// #include <iostream>
// #include <vector>
// #include <limits.h>

// using namespace std;

// #define V 4

// int tsp(int graph[][V], vector<bool>& visited, int currPos, int n, int count, int cost, int& ans) {
//     if (count == n && graph[currPos][0]) {
//         ans = min(ans, cost + graph[currPos][0]);
//         return ans;
//     }

//     for (int i = 0; i < n; i++) {
//         if (!visited[i] && graph[currPos][i]) {
//             visited[i] = true;
//             tsp(graph, visited, i, n, count + 1, cost + graph[currPos][i], ans);
//             visited[i] = false;
//         }
//     }
//     return ans;
// }

// int main() {
//     int graph[V][V] = {
//         {0, 10, 15, 20},
//         {10, 0, 35, 25},
//         {15, 35, 0, 30},
//         {20, 25, 30, 0}
//     };

//     vector<bool> visited(V, false);
//     visited[0] = true;
//     int ans = INT_MAX;

//     ans = tsp(graph, visited, 0, V, 1, 0, ans);

//     cout << "The minimum cost of the Hamiltonian Cycle is " << ans << endl;

//     return 0;
// }




