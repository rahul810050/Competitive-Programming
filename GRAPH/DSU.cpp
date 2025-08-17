#include<bits/stdc++.h>
using namespace std;
const int N = 1e2;
int parent[N];
int sz[N];

void make(int a){
  parent[a] = a;
  sz[a] = 1;
}

int find(int a){
  if(parent[a] == a) return a;
  return parent[a] = (parent[a]);
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

// TC -> O(alpha(n))   ----> alpha(n) -> Reverse Ackerman function

int main(){
  int n, k;
  cin>>n>>k;
  for(int i = 1; i <= n; i++){
    make(i);
  }

  while(k--){
    int u, v; cin>>u>>v;
    Union(u,v);
  }

  int connected_comp = 0;
  for(int i = 1; i <= n; i++){
    if(i == find(i)) connected_comp++;
  }
  cout<<connected_comp<<endl;


  return 0;
}