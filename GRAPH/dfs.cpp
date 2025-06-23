#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;

vector<int> graph[N];
bool visited[N];
vector<vector<int>> cc;
vector<int> currect_cc;

void dfs(int vertex){
  // take action on vertex after entering the vertex
  visited[vertex] = true;
  currect_cc.push_back(vertex);
  for(int child: graph[vertex]){
    if(visited[child]) continue;
    // take action on child before entering the child node 
    dfs(child);
    // take action on child after exiting child node
  }
  // take action on vertex before exiting the vertex
  // TIME COMPLEXITY -> O(V+E)
}

int main(){
  int n, m;
  cin>>n>>m;
  for(int i = 0; i < m; i++){
    int v1,v2; cin>>v1>>v2;
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
  }
  int ct = 0;
  for(int i = 1; i <= n; i++){
    if(visited[i]) continue;
    currect_cc.clear();
    dfs(i);
    cc.push_back(currect_cc);
    ct++;
  }
  cout<<cc.size()<<endl;
  for(auto it: cc){
    for(auto ch: it){
      cout<<ch<<" ";
    } cout<<endl;
  }
}

// code to find connected components