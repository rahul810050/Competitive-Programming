// coded by Cocane

// wood problem from EP 43 of luv playlist

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n,m;
int tree[N];

// it is a monotonic function which returns T T T T F F F F
bool isWoodSufficient(int h){
	long long wood = 0;
	for (int i = 0; i < n; i++)
	{
		if(tree[i] >= h){
			wood += (tree[i] - h);
		}
	}
	return wood >= m;
}

int main(){
	cin>>n>>m;

	for (int i = 0; i < n; i++)
	{
		cin>>tree[i];
	}

	int lo = 1, hi = 1e9, mid;
// T T T T F F F
	while (hi - lo > 1)
	{
		mid = (hi + lo) / 2;
		if(isWoodSufficient(mid)){
			lo = mid;
		} else{
			hi = mid - 1;
		}
	}
	
	if(isWoodSufficient(hi)){
		cout<<hi<<endl;
	} else{
		cout<<lo<<endl;
	}
	// TC : 0(Nlog(n))
}