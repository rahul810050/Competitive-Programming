#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
vector<bool> primes(N, true);
vector<int> lp(N, 0), hp(N, 0);

int main(){
    primes[0] = primes[1] = false;
    for(int i = 2; i * i < N; i++){
        if(primes[i]){
            for(int j = i * i; j < N; j+= i){
                primes[j] = false;
                hp[j] = i;
                if(lp[j] == 0) lp[j] = i;
            }
        }
    }

    int n ; cin>>n;
    vector<int> prime_factors;
    while(n > 1){
        if(primes[n]){
            prime_factors.push_back(n);
            break;
        }
        int primefactor = hp[n];
        while(n % primefactor == 0){
            n /= primefactor;
            prime_factors.push_back(primefactor);
        }
    }
    for(auto it : prime_factors) cout<<it<<" ";
    cout<<endl;
}