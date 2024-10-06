// coded By Cocane

// Q-> Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.The overall run time complexity should be O(log (m+n)).

#include<bits/stdc++.h>
using namespace std;

double findMediun(vector<int> &num1, vector<int> &num2){
	vector<int> v;

	// this is how we can easily merge two or more than two vector into a vector
	// the syntax is pretty cool and easy
	v.insert(v.end(), num1.begin(), num1.end());
	v.insert(v.end(), num2.begin(), num2.end());

	sort(v.begin(), v.end());

	int len = num1.size() + num2.size();

	if(len % 2 == 0){
		return (v[len/2] + v[len/2 - 1]) / 2;
	}
	return v[len/2];
}

int main(){
	int n,m;
	cin>>n>>m;
	
	vector<int> num1(m), num2(n);

	for(auto &it: num1) cin>>it;

	for(auto &it : num2) cin>>it;

	cout<<findMediun(num1,num2);

	return 0;
}