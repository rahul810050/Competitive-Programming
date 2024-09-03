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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {

        string a, b;
        cin >> a >> b;
				// sort(all(a));
				// sort(all(b), greater<char>);

				int n = a.length();

        int counta0 = count(all(a), '0');
        int counta1 = count(all(a), '1');
        int countb0 = count(all(b), '0');
        int countb1 = count(all(b), '1');

				int total0 = counta0 + countb0;
				int total1 = counta1 + countb1;

				for (int i = 0; i < min(total0,total1); i++)
				{
					cout<<"1";
				}

				for (int i = 0; i < n - min(total1,total0); i++)
				{
					cout<<"0";
				} cout<<endl;
				
				

				// int x=min(count1,count0);

        // string str;
				// if (count1 == b.length() || count0 == b.length()){
				// 	str = b;
				// }
				
				// else
        // {
				// 	str = "";
				// 	for (int i = 0; i < a.length(); i++) {
        //     if (a[i] == '0' && count1 > 0) {
        //         str += '1';
        //         count1--;
        //     } else if (a[i] == '1' && count0 > 0) {
        //         str += '0';
        //         count0--;
        //     } else {
				// 			if(count1 > 0) str += '1';
				// 			else if(count0 > 0) str += '0';
				// 		}
            
        // }
				// }

        // string s = "";
        // for (int i = 0; i < str.length(); i++)
        //     s += (a[i] == str[i]) ? '0' : '1';
        
				// out(s);
    }
    return 0;
}
