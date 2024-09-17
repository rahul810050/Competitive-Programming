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
#define MAX_OPS 200000

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
        int N, K;
        cin >> N >> K;
        string A, B;
        cin >> A >> B;

        vector<pair<int, char>> operations;
        bool possible = true;

        for (int i = 0; i <= N - K; ++i) {
            if (A[i] != B[i]) {
                char replace_char = B[i];
                for (int j = i; j < i + K; ++j) {
                    if (B[j] != replace_char) {
                        possible = false;
                        break;
                    }
                }
                if (!possible) break;

                for (int j = i; j < i + K; ++j) {
                    A[j] = replace_char;
                }
                operations.push_back({i + 1, replace_char}); 
            }
        }

        if (possible && A == B && operations.size() <= MAX_OPS) {
            cout << operations.size() << '\n';
            for (auto& op : operations) {
                cout << op.first << ' ' << op.second << '\n';
            }
        } else {
            cout << -1 << '\n';
        }
		}
		return 0;
}