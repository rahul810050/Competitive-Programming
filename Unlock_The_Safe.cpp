// Coded by Cocane

#include <bits/stdc++.h>

#define ll long long
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

int min_moves(int x, int y) {
    return (x-y+9)%9;
}
int max_moves(int x, int y){
    return (y-x+9)%9;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vi a(n), b(n);
        read(a);
        read(b);
        int cc=100;
        int move = 0;
        for (int i = 0; i < n; i++) {
            int xx=min_moves(a[i],b[i]);
            int yy=max_moves(a[i],b[i]);
            int c=min(xx,yy);
            move+=c;
            cc=min(cc,(9-2*c));
        }
        if(move>k) cout<<"No"<<endl;
        else{

            int diff=k-move;
            if(diff%2==0) cout<<"Yes"<<endl;
            else{
                if(diff>=cc) cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
            }
        }
    }
    return 0;
}
