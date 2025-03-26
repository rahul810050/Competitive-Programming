#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while (t--)
	{
		int n, x;
		cin>>n>>x;

		vector<int> v(n);
		for(auto &it: v) cin>>it;

		long long sum = accumulate(v.begin(), v.end(),0);

		long long div = n * x;
		if(div == sum) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
}