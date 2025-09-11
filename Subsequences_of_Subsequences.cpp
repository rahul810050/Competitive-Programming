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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;
  while(t--){
    int N,K;
    cin>>N>>K;
    vector<unsigned int> A(N);
    forn(i,N) cin>>A[i];
    if(K==N){
      unsigned int tot=0;
      forn(i,N) tot ^= A[i];
      if(tot==0) out(1);
      else out(2);
      continue;
    }
    unsigned int base_val[30]={0};
    unsigned long long base_mask[30]={0};
    int r=0;
    vector<unsigned long long> coord(N,0);
    forn(i,N){
      unsigned int x=A[i];
      unsigned long long mask=0;
      for(int b=29;b>=0;b--){
        if((x>>b)&1u){
          if(base_val[b]){
            x ^= base_val[b];
            mask ^= base_mask[b];
          } else {
            base_val[b]=x;
            base_mask[b]=(1ULL<<r);
            mask ^= base_mask[b];
            r++;
            break;
          }
        }
      }
      coord[i]=mask;
    }
    if(K%2==1){
      ll ans = (1LL<<r);
      out(ans);
      continue;
    }
    unsigned long long row_base[31]={0};
    int row_rhs[31]={0};
    bool inconsistent=false;
    forn(i,N){
      unsigned long long m = coord[i];
      int rhs = 1;
      for(int b=r-1;b>=0;b--){
        if((m>>b)&1ULL){
          if(row_base[b]){
            m ^= row_base[b];
            rhs ^= row_rhs[b];
          } else {
            row_base[b]=m;
            row_rhs[b]=rhs;
            m=0;
            break;
          }
        }
      }
      if(m==0 && rhs==1){
        inconsistent=true;
        break;
      }
    }
    int rankB = r;
    if(!inconsistent) rankB = max(0, r-1);
    ll ans = (1LL<<rankB);
    out(ans);
  }
  return 0;
}
