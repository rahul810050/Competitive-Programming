#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
vector<int> g[N];
vector<int> d(N), h(N);

void dfs(int v, int par = 0){
  for(auto child: g[v]){
    if(child == par) continue;
    d[child] = d[v] + 1;
    dfs(child, v);
    h[v] = max(h[v], h[child]+1);
  }
}

int main(){
  int n ; cin>>n;

  for(int i = 1; i < n; i++){
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs(1);

  for(int i = 1; i <= n; i++){
    cout<<i<<" "<<d[i]<<" "<<h[i]<<endl;
  }
  cout<<endl;

}