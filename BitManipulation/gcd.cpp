#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  if(b == 0) return a;
  return gcd(b, a%b);
}

int main(){
  int a, b;
  cin>>a>>b;
  cout<<gcd(a, b)<<endl;
  // lcm(a, b) = (a*b)/ gcb(a,b)
  cout<<(a*b)/gcd(a, b)<<endl;
}