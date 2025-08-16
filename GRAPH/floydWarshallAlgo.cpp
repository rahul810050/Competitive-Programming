#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;

int dist[N][N];

int main(){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(i == j) dist[i][j] == 0;
      dist[i][j] = 1e5;
    }
  }

  int n, m;
  cin>>n>>m;

  vector<vector<pair<int,int>>> g(n);
  for(int i = 0; i < m; i++){
    int x, y, wt;
    cin>>x>>y>>wt;
    dist[x][y] = wt;
  }

  // Floyd Warshall handles negative weighted edges but cant handle negative weighted cycle 

  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        if(dist[i][k] != 1e5 && dist[k][j] != 1e5) // for negative edges
          dist[i][j] = min(dist[i][j], (dist[i][k] + dist[k][j]));
      }
    }
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(dist[i][j] == 1e5) cout<<"I"<<" ";
      else cout<<dist[i][j]<<" ";
    }
    cout<<endl;
  }
}