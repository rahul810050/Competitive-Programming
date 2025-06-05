// POWER OF XOR

// SWAP NUMBERS
#include<bits/stdc++.h>
using namespace std;
int main(){
  // TWO MAIN PROPERTIES OF XOR
  // x ^ x = 0
	// x ^ 0 = x

	int a = 4, b = 3;
	cout<<a<<" "<<b<<endl;
	a = a^b; 
	b = a^b; // b = (a^b) ^ b => a ^ (b ^ b) => a ^ 0 => a
	a = a^b; // a = a ^ (a^b) => a ^ a ^ b => 0 ^ b => b
	cout<<a<<" "<<b<<endl;
}