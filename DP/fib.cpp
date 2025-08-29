#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int dp[N];
// Memoization
// TC becomes linear from exponenciation
// TC => O(2^n) -> O(n)

int fib(int n){
  if(n == 0) return 0;
  if(n == 1) return 1;
  if(dp[n] != -1) return dp[n];
  return dp[n] = fib(n-1)+fib(n-2);
}

int main(){
  memset(dp, -1, sizeof(dp));
  int n;
  cin>>n;
  cout<<fib(n)<<endl;
}