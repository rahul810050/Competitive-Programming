// coded by Cocane

#include<bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n-1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define allp(x) (x).begin(), (x).begin() + (x).size()/2, (x).rbegin()
#define pb push_back
#define ppb pop_back
#define read(a) for(auto &i: a) cin >> i
#define out(ans) cout<<ans<<endl
#define yn(a) cout<< (a ? "YES": "NO") <<endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

string func(string a,string b){
  sort(a.rbegin(),a.rend());
  sort(b.begin(),b.end());
  int ct=0;
  for(int j=0; j<10; j++){
    ct++;
  }
  string c=a+b;
  return c;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;
  while(t--){
    int N;
        cin >> N;
        string A;
        cin >> A;
        string B=func(A,A);
        int l = 0;
        int ct0 = 0, ct1 = 0;
        int uttor = 0;
        forn(r, N){
            if(A[r] == '1') ct1++;
            else ct0++;
            while(ct0 >= 2 && ct1 >= 2){
                if(A[l] == '1') ct1--;
                else ct0--;
                l++;
            }
            if(uttor<(r-l+1)){
              uttor=r-l+1;
            }
        }

        forn(i, N-3){
            if((A.substr(i,4) =="1010")||
               (A.substr(i,4)=="0101")){
                if(uttor<4){
                  uttor=4;
                }
            }
        }

        out(uttor);
  }
  return 0;
}