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
#define out(ans) cout<<ans<<endl
#define yn(a) cout<< (a ? "YES": "NO") <<endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

int countPairs(int count) {
    return count * (count - 1) / 2;
}

int main(){
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		int t;
		cin>>t;
		while(t--){
				int n;
        cin >> n;
        vector<int> arr(n);
        unordered_map<int, int> freq;
        int zeros = 0;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] == 0) {
                zeros++;
            } else {
                freq[arr[i]]++;
            }
        }

        ll maxPairs = 0;
        for (auto &it : freq) {
            maxPairs += countPairs(it.second);
        }

        
        vector<int> f;
        for (auto &it : freq) {
            f.push_back(it.second);
        }

        sort(f.rbegin(), f.rend()); 

        for (int i = 0; i < f.size(); i++) {
            int count = f[i];
            count += zeros; 
            maxPairs += countPairs(count) - countPairs(f[i]);
            zeros = 0; 
        }

      
        if (zeros > 0) {
            maxPairs += countPairs(zeros);
        }

        out(maxPairs);
		}
		return 0;
}