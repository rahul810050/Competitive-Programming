#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

long long power(long long x, long long n){
    if(n == 0){
        return 1;
    }
    long long half = power(x, n / 2);
    long long ans = (half * half) % mod;
    if(n % 2 == 1){
        ans = ans * x;
    }
    return ans;
}

int countGoodNumbers(int n){
    long long ans = (power(5, n) * power(4, n)) % mod;
    return ans;
}

int main(){
    
}