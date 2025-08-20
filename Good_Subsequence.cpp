
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i,n) for(int i=0;i<n;i++)
#define out(x) cout<<(x)<<"\n"

int sum(vector<int>& v) {
    int total = 0;
    for (int x : v) total += x;
    return total;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; 
    if(!(cin>>T)) return 0;
    while(T--){
        int N; cin>>N;
        int l0 = 0, l1 = 0; 
        vector<int> v(N);
        for(int i = 0; i < N; i++) cin>>v[i];
        ll total = sum(v);
        forn(i, N){
            int prev0 = l0, prev1 = l1;
            if((v[i] & 1) == 0) l0 = max(l0, prev1 + 1);
            else l1 = max(l1, prev0 + 1);
        }
        ll ans = 0;

        while(total > 0){
          ans += total/2;
          total -= 2;
        }

        ans += max(l0, l1);
        
        out(max(l0, l1));
    }
    return 0;
}
