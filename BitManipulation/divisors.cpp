#include<bits/stdc++.h>
using namespace std;
// int main(){
//     int n; cin>>n;
//     vector<int> v;
//     for(int i = 1; i * i <= n; i++){
//         if(n % i == 0){
//             v.push_back(i);
//             int x = n / i;
//             if(x != i) v.push_back(x);
//         }
//     }
//     for(auto it:v) cout<<it<<" ";
//     cout<<endl;
// }


int main(){
    int n; cin>>n;
    vector<int> primes;
    for(int i = 2; i * i <= n; i++){
        while(n % i == 0){
            primes.push_back(i);
            n /= i;
        }
    }
    if(n > 1) primes.push_back(n);

    for(auto it: primes) cout<<it<<" ";
    cout<<endl;
    return 0;
}