#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
vector<int> g[N];
vector<bool> vis(N);

bool dfs(int v, int par){
  vis[v] = true;
  for(auto child: g[v]){
    if(!vis[child]){
      vis[child] = true;
      if(dfs(child, v)) return true;
    }
    else if(child != par) return true;
  }
  return false;
}

int main(){
  int n; cin>>n;
  for(int i = 0; i < n; i++){
    int x, y; cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  for(int i = 1; i <= n; i++){
    if(!vis[i]){
      if(dfs(i,-1)){
        cout<<"LOOP EXISTS"<<endl;
        break;
      }
    }
  }
}