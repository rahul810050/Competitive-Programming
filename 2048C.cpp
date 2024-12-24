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
    cin >> t;
    while (t--) {
        string binaryStr;
        cin >> binaryStr;

        int strLen = binaryStr.length();
        int firstZero = -1;

        forn(i, strLen) {
            if (binaryStr[i] == '0') {
                firstZero = i;
                break;
            }
        }

        cout << "1 " << strLen << " ";

        if (firstZero == -1) {
            cout << "1 1" << endl;
            continue;
        }

        int maxMatchLength = 0;
        int optimalStart = 0;
        int remainingLen = strLen - firstZero;

        forn(i, firstZero) {
            if (binaryStr[i] == '1') {
                int currLen = 1;
                while (currLen < remainingLen && 
                      ((binaryStr[i + currLen] - '0') ^ (binaryStr[firstZero + currLen] - '0')) == 1) {
                    currLen++;
                }
                if (currLen > maxMatchLength) {
                    maxMatchLength = currLen;
                    optimalStart = i;
                }
            }
        }

        cout << (optimalStart + 1) << " " << (optimalStart + remainingLen) << endl;
    }

    return 0;
}
