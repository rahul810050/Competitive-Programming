// // coded by Cocane

// #include<bits/stdc++.h>

// #define ll long long
// #define forn(i, n) for(int i = 0; i < n; i++)
// #define for1(i, n) for(int i = 1; i <= n; i++)
// #define foru(i, n) for(int i = n-1; i >= 0; i--)
// #define fi first
// #define se second
// #define all(x) (x).begin(),(x).end()
// #define allp(x) (x).begin(), (x).begin() + (x).size()/2, (x).rbegin()
// #define pb push_back
// #define ppb pop_back
// #define read(a) for(auto &i: a) cin >> i
// #define out(ans) cout<<ans<<endl
// #define yn(a) cout<< (a ? "YES": "NO") <<endl

// using namespace std;

// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef double dl;


// int main(){
// 		ios::sync_with_stdio(false);
// 		cin.tie(NULL);

// 		int n; cin>>n;
// 		vi a(n);
// 		read(a);

// 		unordered_map<int, int> mp;
// 		for(auto &i: a) mp[i]++;

// 		int mx = 0;

// 		for(auto &it: mp){
// 			mx = max(mx, it.se);
// 		}
// 		int ct = 0;
// 		for(auto &it: mp){
// 			if(it.se == mx) ct++;
// 		}
// 		cout<<ct<<endl;
		
// 		return 0;
// }



// coded by Cocane

// #include<bits/stdc++.h>

// #define ll long long
// #define forn(i, n) for(int i = 0; i < n; i++)
// #define for1(i, n) for(int i = 1; i <= n; i++)
// #define foru(i, n) for(int i = n-1; i >= 0; i--)
// #define fi first
// #define se second
// #define all(x) (x).begin(),(x).end()
// #define allp(x) (x).begin(), (x).begin() + (x).size()/2, (x).rbegin()
// #define pb push_back
// #define ppb pop_back
// #define read(a) for(auto &i: a) cin >> i
// #define out(ans) cout<<ans<<endl
// #define yn(a) cout<< (a ? "YES": "NO") <<endl

// using namespace std;

// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef double dl;

// bool isValidSudoku(vector<vector<char>>& board) {
//   vector<vector<int>> row(9, vector<int>(9, 0));

// 	for(auto &it: board){
// 		for(auto &i: it){
// 			if(stoi(i) > 0 && stoi(i) < 10){
// 				row.push_back(stoi(i));
// 			}
// 			else row.push_back(0);
// 		}
// 	}
// 	for(int i = 0; i < 9; i++){
// 		vector<int> col;
// 		for(int j = 0; j < 9; j++){
// 			if(col.find(row[j][i]) != col.end()) return false;
// 			else col.push_back(row[j][i]);
// 		}
// 	}

// 	for(int i = 0; i < 9; i++){
// 		vector<int> col;
// 		for(int j = 0; j < 9; j++){
// 			if(col.find(row[i][j]) != col.end()) return false;
// 			else col.push_back(row[i][j]);
// 		}
// 	}

// 	for (int i = 0; i < count; i++)
// 	{
// 		/* code */
// 	}
	
// }

// int main(){
// 		ios::sync_with_stdio(false);
// 		cin.tie(NULL);

// 		int t;
// 		cin>>t;
// 		while(t--){
				
// 		}
// 		return 0;
// }


// coded by Cocane

#include <bits/stdc++.h>

#define ll long long
#define lli long long int
#define forn(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define foru(i, n) for (int i = n - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ppb pop_back
#define read(a) for (auto &i : a) cin >> i
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<lli> arr(N + 2, 0); 

    int q;
    cin >> q;

    while (q--)
    {
        int a, b, d;
        cin >> a >> b >> d;
        arr[a] += d;
        arr[b + 1] -= d;
    }
		ll mx = LLONG_MIN;

    for (int i = 1; i <= N; i++)
    {
        arr[i] += arr[i - 1];
				mx = max(mx, arr[i]);
    }	

    out(mx);

    return 0;
}
