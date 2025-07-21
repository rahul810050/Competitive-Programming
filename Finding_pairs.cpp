#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> g[N];
vector<int> depth(N);

void dfs(int v, int p=0){
	for(auto child : g[v]){
		if(child == p) continue;
		depth[child] = depth[v] + 1;
		dfs(child, v);
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

	depth[1] = 0;
	dfs(1);
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		ans += (depth[i] + 1);
	}

	cout<<ans<<endl;

}