// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// // Function to compute max profit for a given test case
// int maxProfit(int N, int A, vector<int>& C, vector<int>& D) {
//     vector<int> prefixSum(N + 1, 0); // Prefix sum for fuel costs
//     for (int i = 1; i <= N; i++) {
//         prefixSum[i] = prefixSum[i - 1] + C[i - 1];
//     }

//     int maxProfit = 0;
//     deque<int> maxDq, minDq; // Deques to maintain max and min in the sliding window
//     int L = 0;

//     for (int R = 0; R < N; R++) {
//         // Insert into max and min deques while maintaining decreasing/increasing order
//         while (!maxDq.empty() && D[maxDq.back()] <= D[R]) maxDq.pop_back();
//         while (!minDq.empty() && D[minDq.back()] >= D[R]) minDq.pop_back();
        
//         maxDq.push_back(R);
//         minDq.push_back(R);

//         // Compute gap(L, R) = (maxD - minD)²
//         int maxDiff = D[maxDq.front()] - D[minDq.front()];
//         int gapPenalty = maxDiff * maxDiff;

//         // Compute profit for current [L, R]
//         int segmentSize = R - L + 1;
//         int segmentCost = prefixSum[R + 1] - prefixSum[L];
//         int currentProfit = (A * segmentSize) - segmentCost - gapPenalty;
        
//         maxProfit = max(maxProfit, currentProfit);

//         // Adjust L if necessary to maintain validity
//         while (L <= R && maxProfit < currentProfit) {
//             if (!maxDq.empty() && maxDq.front() == L) maxDq.pop_front();
//             if (!minDq.empty() && minDq.front() == L) minDq.pop_front();
//             L++;
//         }
//     }
    
//     return maxProfit;
// }

// int32_t main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int T;
//     cin >> T;
//     while (T--) {
//         int N, A;
//         cin >> N >> A;
//         vector<int> C(N), D(N);
//         for (int i = 0; i < N; i++) {
//             cin >> C[i] >> D[i];
//         }
//         cout << maxProfit(N, A, C, D) << "\n";
//     }

//     return 0;
// }









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

int maximumSumSubarray(vector<int>& arr, int k) {
	
	// sort(arr.begin(), arr.end());
	// reverse(arr.begin(), arr.end());
	// for(auto &i: arr) cout<<i<<" ";
	int maxsum = 0;
	for (int i = 0; i < arr.size(); i++)
	{ int sum = 0;
		for (int j = i; j < i+k; j++)
		{
			sum += arr[j];
		}
		maxsum = max(maxsum, sum);
	}
	
	return maxsum;
	// for(int i = 0; i < k; i++) sum += arr[i];
	
	// return sum;
}

int main(){
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		int t;
		cin>>t;
		while(t--){
			int n, k;
			cin>>n>>k;
			vi v(n);
			read(v);

			maximumSumSubarray(v, k);

		}
		return 0;
}