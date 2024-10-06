// coded by Cocane

#include<bits/stdc++.h>
using namespace std;

// nth root of a number using Binary Search

double eps = 1e-6;

double multiply(double mid, int n){
	double ans = 1;

	for (int i = 0; i < n; i++)
	{
		ans *= mid;
	}
	return ans;
}

void nthRoot(double &x){
	double lo = 1, hi = x, mid;

	int n; cin>>n; // nth root

	while (hi - lo > eps)
	{
		mid = (hi + lo) / 2;
		// if(mid * mid < x){
		if(multiply(mid, n) < x){
			lo = mid;
		} else{
			hi = mid;
		}
	}
	// N log(10^d);

	cout<<setprecision(6)<<lo<<"\n"<<hi<<endl;


	// this is the another way to find square root of any number
	// cout<<pow(x,1.0/2)<<endl;
	cout<<pow(x,1.0/n)<<endl;
}

int main(){
	double x;
	cin>>x;
	
	nthRoot(x);
}