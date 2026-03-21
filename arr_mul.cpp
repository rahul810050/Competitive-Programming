#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n,q; cin>>n>>q;
  vector<int> v(n+2, 0);

  while (q--)
  {
    int a,b,c; cin>>a>>b>>c;
    v[a] += c;
    v[b+1] -= c; // safe now
  }

  for (int i = 1; i <= n; i++)
  {
    v[i] += v[i-1];  
  }
  
  int mx = *max_element(v.begin() + 1, v.begin() + n + 1); // FIXED range
  cout<<mx<<endl;
}