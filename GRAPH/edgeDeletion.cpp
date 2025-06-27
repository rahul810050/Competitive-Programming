#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
vector<int> g[N];
vector<int> sub_tree(N);
vector<int> val(N);
const int M = 1e9+7;

void dfs(int v, int par){
  sub_tree[v] += val[v];
  for(int child: g[v]){
    if(child == par) continue;
    dfs(child, v);
    sub_tree[v] += sub_tree[child];
  }
}

int main(){
  int n; cin>>n;
  for(int i = 0; i < n-1; i++){
    int x, y;
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs(1,0);

  long long ans = 0;
  for(int i = 2; i <= n; i++){
    int part1 = sub_tree[i];
    int part2 = sub_tree[1] - sub_tree[i];
    ans = max(ans, (part1 * 1LL * part2) % M);
  }
  
}