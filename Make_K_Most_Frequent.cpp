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
				int n, k;
				cin >> n >> k;
				vi arr(n);
				read(arr);

				int targetCount = 0, leftIdx = -1, rightIdx = -1;
				forn(i, n) {
						if (arr[i] == k) {
								if (targetCount == 0) leftIdx = i;
								rightIdx = i;
								targetCount++;
						}
				}

				if (targetCount == 0) {
						out(2);
						continue;
				}

				unordered_map<int, int> freq;
				for (int num : arr) freq[num]++;
				int highestFrequency = 0;
				for (auto& entry : freq) highestFrequency = max(highestFrequency, entry.second);

				if (freq[k] == highestFrequency) {
						out(0);
						continue;
				}

				if (leftIdx == 0 || rightIdx == n - 1) {
						out(1);
						continue;
				}

				unordered_map<int, int> prefixCount, suffixCount;
				int prefixMaxFreq = 0, suffixMaxFreq = 0;

				forn(i, rightIdx + 1) {
						prefixCount[arr[i]]++;
						prefixMaxFreq = max(prefixMaxFreq, prefixCount[arr[i]]);
						if (prefixCount[k] == prefixMaxFreq) {
								out(1);
								goto endCase;
						}
				}

				foru(i, n) {
						if (i < leftIdx) break;
						suffixCount[arr[i]]++;
						suffixMaxFreq = max(suffixMaxFreq, suffixCount[arr[i]]);
						if (suffixCount[k] == suffixMaxFreq) {
								out(1);
								goto endCase;
						}
				}

				out(2);

		endCase:;
		}
		return 0;
}
