#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e4+7;

int binaryExpoRecur(int a, int b){
  if(b == 0) return 1;
  long long ans = binaryExpoRecur(a, b/2) ;
  if(b & 1) return ((a * (ans * 1LL * ans)) % MOD);
  else return ((ans * 1LL * ans) % MOD);
}

// int binaryExpoIter(int a, int b){
//   long long ans = 1;
//   while(b > 0){
//     if(b & 1) ans = (ans * 1LL * a) % MOD;
//     a = (a * 1LL * a) % MOD;
//     b >>= 1;
//   }
//   return ans;
// }

// when a <= 10^18 , MOD <= 10^18 
int binaryExpoIter(long long a, long long b){
  // a %= MOD;
  int ans = 1;
  while(b > 0){
    if(b & 1) ans = binaryMultiply(ans, a);
    a = binaryMultiply(a, a);
    b >>= 1;
  }
  return ans;
}

int binaryMultiply(long long a, long long b){
  int ans = 0;
  while(b > 0){
    if(b & 1) ans = (ans + a) % MOD;
    a = (a + a) % MOD;
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