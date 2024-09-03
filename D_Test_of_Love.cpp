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
// #define out(ans) cout<<ans<<endl
// #define yn(a) cout<< (a ? "YES": "NO") <<endl

// using namespace std;

// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef double dl;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;
//     while(t--){
//         int n, m, k;
//         cin >> n >> m >> k;

//         string s;
//         cin >> s;

//         bool flag = true;

//         if(m > n) {
//             cout << "YES" << endl;
//             continue;
//         }

// 				else{
// 					m--;

//         for(int i = 0; i < s.length(); i++) {
//             if(s[i] == 'W') {
//                 if(k > 0) {
//                     k--;
//                 } else if(m > 0) {
//                     m--;
//                 } else {
//                     flag = false;
//                     break;
//                 }
//             } else if(s[i] == 'C') {
//                 if(m > 0) {
//                     m--;
//                 } else {
//                     flag = false;
//                     break;
//                 }
//             }
            
//         }

// 				}

//         if(flag) {
//             cout << "YES" << endl;
//         } else {
//             cout << "NO" << endl;
//         }
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
#define out(ans) cout<<ans<<endl
#define yn(a) cout<< (a ? "YES": "NO") <<endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

void run(){
	int n,m,k;
	string river;
	cin>>n>>m>>k>>river;

	river = 'L' + river + 'L';

	int current = 0, swim = 0;

	while (current <= n)
	{
		if(river[current] == 'C'){
			break;
		}

		if(river[current] == 'W'){
			current++;
			swim++;
			continue;
		}

		assert(river[current] == 'L');
		bool jumped = false;

		for (int i = min(current + m, n+ 1); i > current; i--)
		{
			if(river[i] == 'L'){
				current = i;
				jumped = true;
				break;
			}
		}

		if(jumped) continue;

		for (int i = min(current + m, n + 1); i > current; i--)
		{
			if(river[i] == 'W'){
				current = i;
				jumped = true;
				break;
			}
		}
		
		if(!jumped) break;

		

	}

	cout<<(current > n && swim <= k ? "YES": "NO")<<endl;
	
	
}

int main(){
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		int t;
		cin>>t;
		while(t--){
				run();
		}
		return 0;
}