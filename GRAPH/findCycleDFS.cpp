#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
vector<int> g[N];
bool v[N];

bool dfs(int vertex, int par){
  v[vertex] = true;
  bool isLoopExist = false;
  for(int child: g[vertex]){
    if(v[child] && child == par) continue;
    if(v[child]) return true;
    isLoopExist |= dfs(child, vertex);
  }
  return isLoopExist;
}

int main(){
  int n, m;
  cin>>n>>m;
  for(int i = 0; i < m; i++){
    int v1, v2;
    cin>>v1>>v2;
    g[v1].push_back(v2);
    g[v2].push_back(v1);
  }

  bool isLoopExist = false;
  int loop_ct = 0;
  for(int i = 1; i <= n; i++){
    if(v[i]) continue;
    if(dfs(i, 0)){
      // isLoopExist = true;
      // break;
      loop_ct++;
    }
  }
  cout<<loop_ct<<endl;
  // cout<<isLoopExist<<endl;
}