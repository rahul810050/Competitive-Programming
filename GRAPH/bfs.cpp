#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
vector<int> g[N];
vector<bool> vis(N);
vector<int> level(N);


void bfs(int source){
  queue<int> q;
  q.push(source);
  vis[source] = true;
  while (!q.empty())
  {
    int curr_v = q.front();
    cout<<curr_v<<" ";
    q.pop();
    for(int child: g[curr_v]){
      if(!vis[child]){
        q.push(child);
        vis[child] = true;
        level[child] = level[curr_v] + 1;
      }
    }
  }
  // TC -> O(V+E)
  // BFS IS USED TO FIND THE SHORTEST PATH OF A NODE FROM ROOT IF THE WEIGHT OF ALL THE EDGES ARE EQUAL
  cout<<endl;
}

int main(){
  int n ; cin>>n;
  for (int i = 0; i < n; i++)
  {
    int x,y; cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  bfs(1);

  for(int i = 1; i <= n; i++){
    cout<<i<<": "<<level[i]<<endl;
  }
  
}