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
    string s; cin>>s;
    string t = "";
    int ct0 = count(all(s), '0');
    int ct1 = count(all(s), '1');
    // cout<<"zero and one count"<<" ";
    // cout<<ct0<<" "<<ct1<<endl;
    bool f = false;
    for(int i = 0; i < s.length(); i++){
      if(s[i] == '0'){
        if(ct1 > 0){
          t += '0';
          ct1--;
        } else {
          f = true;
          break;
        }
      } else if(s[i] == '1'){
        if(ct0 >0){
          t += '1';
          ct0--;
        } else {
          f = true;
          break;
        }
      }
      if(f) break;
    }

    cout<<s.length() - t.length()<<endl;
    
  }
  return 0;
}