#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generateSubset(vector<int> &v){
  int n = v.size();
  int subset_ct = (1 << n);
  vector<vector<int>> subsets;
  for(int mask = 0; mask < subset_ct; mask++){
    vector<int> subset;
    for(int i = 0; i < n; i++){
      if(mask & (1 << i)) subset.push_back(v[i]);
    }
    subsets.push_back(subset);
  }
  return subsets;
}

int main(){
  int n; cin>>n;
  vector<int> v(n);
  for(auto &it : v) cin>>it;
  vector<vector<int>> ans = generateSubset(v);
  for(auto &subset : ans){
    for(auto &it : subset) cout<<it<<" ";
    cout<<endl;
  }
}