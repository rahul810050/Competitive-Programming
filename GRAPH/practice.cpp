// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e3+10;

// vector<int> g[N];
// bool vis[N];
// vector<vector<int>> connectedComp;
// vector<int> cc;

// void dfsForConnectedComp(int v, int p = -1){
//   vis[v] = true;
//   cc.push_back(v);
//   for(auto child: g[v]){
//     if(child != p && !vis[child]){
//       vis[child] = true;
//       dfsForConnectedComp(child, v);
//     }
//   }
// }

// int main(){
  
//   int n,m; cin>>n>>m;
//   // iterating to store the nodes
//   for(int i = 0; i < m; i++){
//     int v,u; cin>>v>>u;
//     // v - u
//     g[v].push_back(u);
//     // u - v for undirected graphs
//     g[u].push_back(v);
//   }
//   // dfsForConnectedComp(1);
//   int ct = 0;
//   for(int i = 1; i <= n; i++){
//     // check if visited or not
//     if(!vis[i]){
//       // clear the current connected component 
//       cc.clear();
//       // dfs call for unvisited node
//       dfsForConnectedComp(i);
//       // pushing the whole component vec into connectedComp
//       connectedComp.push_back(cc);
//       // increatment of counter
//       ct++;
//     }
//   }

//   // print all the connected component
//   for(auto i: connectedComp){
//     for(auto j: i){
//       cout<<j<<" ";
//     }
//     cout<<endl;
//   }
//   cout<<ct<<endl;


  
// }


// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e3+10;

// vector<int> g[N];
// bool vis[N];

// bool findCycle(int v, int p=-1){
//   vis[v] = true;
//   bool isLoopExist = false;
//   for(auto child: g[v]){
//     if(vis[child] && child != p) return true;
//     if (vis[child]) return true;
//     isLoopExist |= findCycle(child, v);
//   }
//   return isLoopExist;
// }

// int main(){
//   int n,m;
//   cin>>n>>m;
//   for(int i = 0; i < m; i++){
//     int v, u; cin>>v>>u;
//     g[v].push_back(u);
//     g[u].push_back(v);
//   }
//   bool isLoopExists = false;
//   for(int i = 1; i <= n; i++){
//     if(!vis[i]) {
//       if(findCycle(i)){
//         isLoopExists = true;
//         break;
//       }
//     }
//   }
//   cout<<isLoopExists<<endl;
// }

// Find Diameter
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e3+10;

// vector<int> g[N];
// vector<int> depth(N);
// vector<int> height(N);

// void dfs(int v, int p = -1){
//   for(auto child: g[v]){
//     if(child == p) continue;
//     depth[child] = depth[v]+1;
//     dfs(child, v);
//     height[v] = max(height[v], height[child]+1);
//   }
// }

// void findDiameter(int v, int p=-1){
//   for(auto child: g[v]){
//     if(child == p) continue;
//     depth[child] = depth[v]+1;
//     findDiameter(child, v);
//   }
// }

// int main(){
//   int n, m;
//   cin>>n>>m;
//   for(int i = 0; i < m; i++){
//     int v,u;
//     cin>>v>>u;
//     g[v].push_back(u);
//     g[u].push_back(v);
//   }
//   // dfs(1);
//   // for(int i = 1; i <= n; i++){
//   //   cout<<i<<" "<<depth[i]<<" "<<height[i]<<endl;
//   // }

//   // Diameter of the tree
//   fill(depth.begin(), depth.end(), 0);
//   findDiameter(1);
//   int mx_diameter = -1;
//   int mx_d_node;
//   for(int i = 1; i <= n; i++){
//     if(mx_diameter < depth[i]){
//       mx_diameter = depth[i];
//       mx_d_node = i;
//     }
//     depth[i] = 0;
//   }
//   findDiameter(mx_d_node);
//   mx_diameter = *max_element(depth.begin(), depth.end());
//   cout<<mx_diameter<<endl;
// }


// Find LCA of two nodes

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e3+10;
// vector<int> g[N];
// int par[N];

// void dfs(int v, int p=-1){
//   par[v] = p;
//   for(auto child: g[v]){
//     if(child == p) continue;
//     dfs(child, v);
//   }
// }

// vector<int> path(int v){
//   vector<int> vec;
//   while (v != -1)
//   {
//     vec.push_back(v);
//     v = par[v];
//   }
//   reverse(vec.begin(), vec.end());
//   return vec;
// }

// int main(){
//   int n, m;
//   cin>>n>>m;
//   for(int i = 0; i < m; i++){
//     int v,u; cin>>v>>u;
//     g[v].push_back(u);
//     g[u].push_back(v);
//   }
//   dfs(1);
//   int x,y; cin>>x>>y;
//   vector<int> path_x = path(x);
//   vector<int> path_y = path(y);
//   int lca = -1;
//   int len = min(path_x.size(), path_y.size());
//   for(int i = 0; i < len; i++){
//     if(path_x[i] == path_y[i]){
//       lca = path_x[i];
//     } else break;
//   }
//   cout<<lca<<endl;
// }


// Edge deletion 

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e3+10;
// vector<int> g[N];
// int subtree_sub[N];
// int val[N];
// const int M = 1e9;

// void dfs(int v, int p=-1){
//   subtree_sub[v] += val[v];
//   for(auto child: g[v]){
//     if(child == p) continue;
//     dfs(child, v);
//     subtree_sub[v] += subtree_sub[child];
//   }
// }

// int main(){
//   int n, m; cin>>n>>m;
//   for(int i = 0; i < m; i++){
//     int v,u; cin>>v>>u;
//     g[v].push_back(u);
//     g[u].push_back(v);
//   }
//   for(int i = 1; i <= n; i++){
//     cin>>val[i];
//   }
//   dfs(1);
//   long long ans = 0;
//   for(int i = 2; i <= n; i++){
//     int part1 = subtree_sub[i];
//     int part2 = subtree_sub[1] - part1;
//     ans = max(ans, (part1 * 1LL * part2) % M);
//   }
//   cout<<ans<<endl;
// }


// BFS
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e3+10;
// vector<int> g[N];
// bool vis[N];
// int level[N];
// void bfs(int source){
//   queue<int> q;
//   q.push(source);
//   vis[source] = true;
//   while (!q.empty())
//   {
//     int curr_v = q.front(); q.pop();
//     for(auto child : g[curr_v]){
//       if(!vis[child]){
//         q.push(child);
//         vis[child] = true;
//         level[child] = level[curr_v] + 1;
//       }
//     }
//   }
// }



// NAKANJ

// #include <bits/stdc++.h>
// using namespace std;
// const int INF = 1e9+10;
// int vis[8][8];
// int level[8][8];

// vector<pair<int,int>> movements = {
//   {2,1}, {2,-1}, {-2, 1}, {-2, -1}, 
//   {1,2}, {1, -2}, {-1, 2}, {-1, -2}
// };

// int intX(string s){
//   return s[0] - 'a';
// }

// int intY(string s){
//   return s[1] - '1';
// }

// bool isValid(int i, int j){
//   return i < 8 && i >= 0 && j >= 0 && j < 8;
// }

// int bfs(int i, int j, int des_x, int des_y){
//   queue<pair<int,int>> q;
//   q.push({i, j});
//   vis[i][j] = true;
//   level[i][j] = 0;
//   while(!q.empty()){
//     auto curr = q.front(); q.pop();
//     int x = curr.first;
//     int y = curr.second;
//     if(x == des_x && y == des_y) return level[x][y];
//     for(auto move: movements){
//       int newX = x + move.first;
//       int newY = y + move.second;
//       if(!isValid(newX, newY) || vis[newX][newY]) continue;
//       vis[newX][newY] = true;
//       level[newX][newY] = level[x][y] + 1;
//       q.push({newX, newY});
//     }
//   }
//   return -1;
// }

// void reset(){
//   for(int i = 0; i < 8; i++){
//     for(int j = 0; j < 8; j++){
//       vis[i][j] = false;
//       level[i][j] = INF;
//     }
//   }
// }

// int main(){
//   int t; cin>>t;
//   while (t--)
//   {
//     string start, des;
//     cin>>start>>des;
//     int start_x = intX(start);
//     int start_y = intY(start);
//     int des_x = intX(des);
//     int des_y = intY(des);
//     reset();
//     int steps = bfs(start_x, start_y, des_x, des_y);
//     cout<<steps<<endl;
//   }
// }



// Dijkstra

#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
vector<pair<int,int>> g[N];


void 

int main(){

}