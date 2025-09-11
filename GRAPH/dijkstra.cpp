#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
const int INF = 1e8+10;
vector<pair<int,int>> g[N];
vector<int> dist(N, INF);
vector<bool> vis(N, false);

int dijkstra(int source, int n){
    set<pair<int,int>> st;
    st.insert({0,source});
    while(st.size()>0){
        auto it = *st.begin();
        int v = it.second;
        int v_dist = it.first;
        if(vis[v]) continue;
        vis[v] = true;
        for(auto child: g[v]){
            int child_v = child.first;
            int wt = child.second;
            if(wt + dist[v] < dist[child_v]){
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }
    // TC -> O(v+e*log(v))
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(dist[i] == INF) return -1;
        ans = max(ans, dist[i]);
    }
    
    return ans;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int u,v,wt; cin>>u>>v>>wt;
        g[u].push_back({v,wt});
        g[v].push_back({u,wt});
    }
    int source; cin>>source;
    cout<<dijkstra(source, n)<<endl;
}