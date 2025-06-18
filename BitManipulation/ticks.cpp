// 6 ticks I must know


// tick 1 -> a number is odd or even 
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// 	int n; cin>>n;
// 	if((n & 1) == 0) cout<<"even"<<endl;
// 	else if((n & 1) == 1) cout<<"odd"<<endl;
// }


// tick 2 -> multiplication of any number with 2
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// 	int n = 5;
// 	cout<<(n << 1)<< endl; // 10
// 	cout<<(n >> 1)<<endl; // 2
// 	// (hi + lo) >> 1 === (hi + lo) / 2;
// 	// 101 --> (2^2*1 + 2^1*0 + 2^0*1)
// 	// 10 --> (2^1*1 + 2^0*0 + 2^0*1) -> 5 / 2
// 	// 1010 --> (2^3*1 + 2^2*0 + 2^1*1) -> 5 * 2

// 	cout<<(5 << 3)<<endl; // 5 * 8 = 40;
// }


// tick 3 -> Upper case and Lower case letters
// #include<bits/stdc++.h>
// using namespace std;

// void printBinary(int n){
// 	for(int i = 10; i >= 0; i--){
// 		cout<<((n >> i) & 1);
// 	}
// 	cout<<endl;
// }
// // 'A' -> 1000001 to convert a upper case letter to a lower case letter we have to just do set of 5th bit of upper case letter and vice verse
// // 'a' -> 1100001

// int main(){
// 	// for(char i = 'A'; i <= 'D'; i++){
// 	// 	cout<<i<<endl;
// 	// 	printBinary(int(i));
// 	// }
// 	// for(char i = 'a'; i <= 'd'; i++){
// 	// 	cout<<i<<endl;
// 	// 	printBinary(int(i));
// 	// }

// 	// char A = 'A';
// 	// int a = A | (1<<5); // 97
// 	// char a = A | (1<<5); // a
// 	// cout<<a<<endl;

// 	// char b = 'b';
// 	// char B = b & (~(1<<5));
// 	// cout<<B<<endl;
// 	printBinary(int(' ')); // ' ' -> 100000
// 	printBinary(int('_')); // '_' -> 1011111
//  	cout<< char('c' & '_')<<endl; // 1100011 & 1011111 = 1000011 -> 'C'

// 	// uppercase to lowercase
// 	char A = 'A';
// 	char a = A | ' '; // OR with 'space'
// 	cout<<a<<endl;
// 	// lowercase to Uppercase
// 	char b = 'b';
// 	char B = b & '_';
// 	cout<<B<<endl;
// }


// tick 4 -> clear LSB & MSB till ith bit
// #include<bits/stdc++.h>
// using namespace std;

// void printBinary(int n){
// 	for(int i = 10; i >= 0; i--){
// 		cout<<((n >> i) & 1);
// 	} cout<<endl;
// }
// for LSB
// int main(){
// 	printBinary(59); // 111011 
// 	int a = 59; // 111011 to clear LSB till 4th bit we have to do AND with 11111100000
// 	// now how will we find 100000 
// 	int x = ~((1 << (4+1)) - 1);
// 	int y = a & x;
// 	printBinary(y); // 100000
// }

// for MSB
// int main(){
// 	int a = 59;
// 	printBinary(a);// 111011 to clear MSB till 3th bit we have to do AND with 0000001111
// // now how will we find 000001111 
// 	int x = ((1<<(3+1)) - 1); // 001111
// 	int y = a & x;
// 	printBinary(y); // 001011
// }


// tick 5 -> to check number is power of 2 or not??
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// 	int n; cin>>n;
// 	// if n is power of 2 then it will be like 1000 so (n-1) will be 0111
// 	// if we take AND between n & (n-1) it will give 00000 
// 	if(n & (n-1)) cout<<"not a power of 2"<<endl;
// 	else cout<<"power of 2"<<endl;
// }




#include<bits/stdc++.h>
using namespace std;

string printBinary(long long n){
	string s = "";
	for(int i = 50; i >=0; i--){
			s += ((n >> i) & 1) + '0';
	}
	return s;
}

void minBitFlips(int start, int goal) {
	string s = printBinary(start);
	string g = printBinary(goal);
	cout<<s<<" "<<g<<endl;

	int ct = 0;
	for(int i = 0; i< 50; i++){
		if(s[i] != g[i]) ct++;
	}
	cout<<ct+1<<endl;
	// return ct;
}

int main(){
	int start, goal;
	cin>>start>>goal;
	minBitFlips(start, goal);
}