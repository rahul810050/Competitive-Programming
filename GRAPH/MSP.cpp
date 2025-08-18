#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int parent[N], sz[N];

void make(int v){
  parent[v] = v;
  sz[v] = 1;
}

int find(int v){
  if(parent[v] == v) return v;
  return parent[v] = find(parent[v]);
}

void Union(int a, int b){
  a = find(a);
  b = find(b);
  if(a != b){
    if(sz[a] < sz[b]) swap(a,b);
    parent[b] = a;
    sz[a] += sz[b];
  }
}

int main(){
  int n, m;
  cin>>n>>m;
  vector<pair<int,pair<int,int>>> g;
  for(int i = 0; i < m; i++){
    int u, v, wt;
    cin>>u>>v>>wt;
    g.push_back({wt, {u, v}});
  }
  for(int i = 1; i <= n; i++) make(i);

  sort(g.begin(), g.end());

  int total_cost = 0;

  for(auto it : g){
    int wt = it.first;
    int u = it.second.first;
    int v = it.second.second;
    if(find(u) == find(v)) continue;
    Union(u,v);
    cout<<u<<" "<<v<<endl;
    total_cost += wt;
  }
  cout<<total_cost<<endl;
}