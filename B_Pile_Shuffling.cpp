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

ll a1 = 0;
ll b1 = 0;
ll c1 = 0;

bool isBig(int x,int y){
  return x > y;
}

void check_zero(int x, int y){
  if(isBig(x,y)) a1 += (x - y);
}

void check_one(int x, int y, int p, int q){
  if(x > y){
    b1 += (x - y);
    c1 += min(p,q);
  }
}

ll uttor = 0;

void sum(int x, int y, int z){
  uttor = x+y+z;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    a1 = 0;
    b1 = 0;
    c1 = 0;
    uttor = 0;
    vll a(n), b(n), c(n), d(n);
    forn(i,n) cin>>a[i]>>b[i]>>c[i]>>d[i];

    

    forn(i,n){
      check_zero(a[i], c[i]);
      check_one(b[i], d[i], a[i], c[i]);
    }

    sum(a1,b1,c1);
    out(uttor);
  }
  return 0;
}