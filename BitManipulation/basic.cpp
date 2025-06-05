// #include<bits/stdc++.h>
// using namespace std;

// int main(){
// 	cout<<INT_MAX<<endl;
// 	int a = (1LL<<31) -1; // when we add LL means that 1 is a long long number 
// 	unsigned int a = (1LL<<32) -1; // unsigned means that it will not be negative---- but int is a signed means 1 bit is reserved for positive and negative
// 	cout<<a<<endl;

// }


// how to check if a bit is set or not 
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// 	int num = 63;
// 	// if we want to check 2nd bit is set or not ??
// 	cout<<((num & (1<<3)) == 0 ? "not set " : "set")<<endl;
// }


// how to make a bit set in any number ??
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// 	int n = 9;
// 	// if want to make 2rd bit set then we have to do OR with 1 << i number 
// 	cout<<(n | (1 << 2))<<endl;
// }


// how to make a bit unset in any number ??
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
// 	int n = 10; // 1010
// 	// if we want to unset the 1st bit we have to AND with ~ (1 << i)
// 	cout<<(n & (~(1 << 1)))<<endl; // 1000-> 8
// }

// how to toggle a bit ?
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// 	int n = 10; // 1010
// 	// if i want to toggle bit 1st we have to do XOR with ( 1 << i) this number
// 	cout<<(n ^ (1 << 1))<<endl; // 1000-> 8
// }



// how to check number of set bits
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n = 10; // 1010
	// if we want to check how many set bit is there
	int ct = 0;
	for(int i = 31; i >= 0; i--){
		if((n & (1 << i)) != 0) ct++;
	}
	cout<<ct<<endl;

	// builtin function to count set bits in a number
	cout<<__builtin_popcount(9)<<endl;
	cout<<__builtin_popcountll(1LL << 35)<<endl; // numbers which have more than 31 bits
	cout<<__builtin_popcountll((1LL << 35) - 1)<<endl; // numbers which have more than 31 bits
}


// how to print the binary represantation of any number
// #include<bits/stdc++.h>
// using namespace std;

// void printBinary(int n){
// 	for(int i = 10; i >= 0; i--){
// 		cout<<((n >> i) & 1); // it is right shifting the ith bit to 0th bit and then doing AND with 1
// 	}
// }

// int main(){
// 	int n = 10;
// 	printBinary(n);
// 	return 0;
// }