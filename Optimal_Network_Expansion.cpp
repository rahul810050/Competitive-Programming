#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> g[N];
vector<bool> vis(N);
vector<vector<int>> connected;
vector<int> connected_cc(N);

void dfs(int v, int par= -1){
	vis[v] = true;
	connected_cc.push_back(v);
	for(auto child : g[v]){
		if(child == par) continue;
		if(!vis[child]){
			dfs(child, v);
		} 
	}
}


int main() {
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 0; i < m; i++){
		int x,y; cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}	

	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			connected_cc.clear();
			dfs(i);
			connected.push_back(connected_cc);
		}
	}

	vector<int> vec;
	k++;

	for(auto it: connected){
		vec.push_back(it.size());
	}

	sort(vec.begin(), vec.end(), greater<int>());

	int total_networks = 0;
	int x = 0;
	for(auto it: vec){
		total_networks += it;
		x++;
		if(x == k) break;
	}

	cout<<total_networks<<endl;

	return 0;
}