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

void answer()
{
    long long a,b;
    cin >> a >> b;
    if(a%2 == 0 && b%2 == 0){
        cout << "Yes"<<endl;
        return;
    }
    if(a%2 == 0 && b%2 == 1){
        if(b == 1){
            cout << "No"<<endl;
        } else{
            cout << "Yes"<<endl;
        }
        return;
    }
    if(a%2 == 1 && b%2 == 0){
        if(a == 1){
            cout << "No"<<endl;
        } else{
            cout << "Yes"<<endl;
        }
        return;
    }
    if(a%2 == 1 && b%2 == 1){
        cout << "No"<<endl;
        return;
    }
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t;
        cin>>t;
        while(t--){
            answer();
        }
        return 0;
}