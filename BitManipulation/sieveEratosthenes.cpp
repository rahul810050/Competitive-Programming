// #include<bits/stdc++.h>
// using namespace std;



// int main(){
// 	int n; cin>>n;
// 	vector<bool> prime(n + 1, true);
// 	prime[0]=prime[1]=false;
// 	for(int i = 2; i*i <= n; i++){
// 		if(prime[i] == 1){
// 			for(int j = i*i; j <= n; j += i){
// 				prime[j] = false;
// 			}
// 		}
// 	}
// 	for(int i = 2; i <= n; i++){
// 		if(prime[i]) cout<<i<<" ";
// 	}
// 	cout<<endl;
// }



#include<bits/stdc++.h>
using namespace std;

vector<int> primesInRange(vector<vector<int>>& queries) {
	int hi = INT_MIN;
	for (auto row : queries) {
			auto it = max_element(row.begin(), row.end());
			if (it != row.end()) hi = max(hi, *it);  // FIXED
	}

	vector<bool> prime(hi + 1, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= hi; i++) {
			if (prime[i]) {
					for (int j = i * i; j <= hi; j += i) {
							prime[j] = false;  // FIXED
					}
			}
	}

	vector<int> prefix(hi + 1, 0);
	for (int i = 1; i <= hi; i++) {
			prefix[i] = prefix[i - 1] + (prime[i] ? 1 : 0);
	}

	vector<int> allPrime;
	for (int i = 0; i < queries.size(); i++) {
			int ctPrime = prefix[queries[i][1]] - (queries[i][0] > 0 ? prefix[queries[i][0] - 1] : 0);
			allPrime.push_back(ctPrime);
	}

	return allPrime;
}

int main(){
	int n; cin>>n;
	vector<vector<int>> vec(n,vector<int>(2));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2; j++){
			int x;  cin>> x;
			vec[i][j] = x;
		}
	}
	vector<int> v = primesInRange(vec);
	for(auto it: v) cout<<it<<" ";
	cout<<endl;
}