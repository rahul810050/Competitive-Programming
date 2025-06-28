#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9+10;
bool vis[8][8];
int level[8][8];
vector<pair<int,int>> dir = {
  {1,2}, {-1,2},
  {1,-2}, {-1, -2},
  {-2,1}, {-2, -1},
  {2, 1}, {2, -1}
};

int getX(string s){
  return s[0] - 'a';
}

int getY(string s){
  return s[1] - '1';
}

void resetArr(){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      vis[i][j] = false;
      level[i][j] = INF;
    }
  }
}

bool isValid(int x, int y){
  return x < 8 && y < 8 && x >= 0 && y >= 0; 
}

int bfs(string source, string dest){
  int sourceX = getX(source);
  int sourceY = getY(source);
  int destX = getX(dest);
  int destY = getY(dest);

  queue<pair<int,int>> q;
  q.push({sourceX, sourceY});
  vis[sourceX][sourceY] = true;
  level[sourceX][sourceY] = 0;
  while(!q.empty()){
    pair<int, int> v = q.front();
    q.pop();
    int x = v.first, y = v.second;
    for(auto it: dir){
      int childX = it.first + x, childY = it.second + y;
      if(!isValid(childX, childY)) continue;
      if(!vis[childX][childY]){
        q.push({childX, childY});
        vis[childX][childY] = true;
        level[childX][childY] = level[x][y] + 1;
      }
      const int INF = 1e9+10;
    }
    if(level[destX][destY] != INF) break;
  }

  return level[destX][destY];
}



int main(){
  int t; cin>>t;
  while (t--)
  {
    resetArr();
    string s1,s2; cin>>s1>>s2;
    cout<<bfs(s1,s2)<<endl;
  }
  
}