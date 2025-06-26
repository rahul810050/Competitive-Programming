#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
vector<int> g[N];
vector<int> subtree_sum(N), even_ct(N);

// sum of subtree and number of even numbers in that subtree
void dfs(int vertex, int par = 0){
  if(vertex % 2 == 0) even_ct[vertex]++;
  subtree_sum[vertex] += vertex;

  for(int child : g[vertex]){
    if(child == par) continue;
    dfs(child, vertex);

    subtree_sum[vertex] += subtree_sum[child];
    even_ct[vertex] += even_ct[child];
  }
}

int main(){
  int n;
  cin>>n;
  for(int i = 0; i < n-1; i++){
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1);
  cout<<endl;
  for(int i = 1; i <= n; i++){
    cout<<i<<" "<<even_ct[i]<<" "<<subtree_sum[i]<<endl;
  }
  // cout<<endl;
}