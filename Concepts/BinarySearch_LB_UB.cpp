#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector<int>&v, int element){
	int lo = 0, hi = v.size() - 1;
	int mid;

	while (hi - lo > 1)
	{
		mid = (hi + lo) / 2;
		if(v[mid] < element){
			lo = mid + 1;
		} else{
			hi = mid;
		}
	}

	if(v[lo] >= element){
		return lo;
	}
	if(v[hi] >= element){
		return hi;
	}
	return -1;
	
}

int upper_bound(vector<int> &v, int element){
	int lo = 0, hi = v.size() - 1;
	int mid;
	
	while (hi - lo > 1)
	{
		mid = (hi + lo) / 2;
		if(v[mid] <= element){
			lo = mid + 1;
		} else{
			hi = mid;
		}
	}
	
	if(v[lo] > element){
		return lo;
	}
	if(v[hi] > element){
		return hi;
	}
	return -1;
}

int main(){
	int n; cin>>n;
	vector<int> v(n);

	for(auto &it : v) cin>>it;

	int element;
	cin>>element;

	int lb = lower_bound(v, element);
	int ub = upper_bound(v, element);

	cout<<lb<<" "<<(lb != -1? v[lb]: -1)<<endl;
	cout<<ub<<" "<<(ub != -1?v[ub]: -1)<<endl;

}