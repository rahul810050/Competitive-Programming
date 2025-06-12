#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e4+7;

int binaryExpoRecur(int a, int b){
  if(b == 0) return 1;
  long long ans = binaryExpoRecur(a, b/2) ;
  ans = (ans * ans) % MOD;
  if(b & 1) ans = (a * ans) % MOD;
  return ans;
}

int binaryExpoIter(int a, int b){
  long long ans = 1;
  while(b > 0){
    if(b & 1) ans = (ans * a);
    a *= a;
    b >>= 1;
  }
  return ans;
}

int main(){
  int a, b;
  cin>>a>>b;
  cout<<pow(a, b)<<endl;
  cout<<(a<<(b-1))<<endl;

  cout<<binaryExpoRecur(a, b)<<endl;
  cout<<binaryExpoIter(a, b)<<endl;
} 