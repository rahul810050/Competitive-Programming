#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ppb pop_back
#define out(ans) cout<<ans<<endl
using namespace std;
typedef vector<int> vi;
typedef vector<ll> vll;

ll addv(ll &x, ll v){
    x += v;
    return x;
}
ll subv(ll &x, ll v){
    x -= v;
    return x;
}
inline bool lt(int a, int b){
    return a < b;
}
inline bool tr(bool v){
    return v;
}

void build_f(int n, const vi &A, const vi &B, vector<array<int,2>> &f){
    f[n][0] = n;
    f[n][1] = n;
    
    int i = n - 1;
    while(i >= 1){
        int c = 0;
        while(c < 2){
            int cur;
            if(c == 0){
                cur = A[i];
            } else {
                cur = B[i];
            }

            int v0 = A[i + 1];
            int v1 = B[i + 1];

            bool ok0 = lt(cur, v0);
            bool ok1 = lt(cur, v1);

            int cand0 = i;
            int cand1 = i;

            if(tr(ok0)){
                cand0 = max(cand0, f[i + 1][0]);
            }
            if(tr(ok1)){
                cand1 = max(cand1, f[i + 1][1]);
            }

            int bst = cand0;
            if(cand1 > bst){
                bst = cand1;
            }

            f[i][c] = bst;
            c++;
        }
        i--;
    }
}

ll compute_ans(int n, const vector<array<int,2>> &f){
    ll res = 0;
    int i = 1;
    while(i <= n){
        int reach = max(f[i][0], f[i][1]);
        ll len = (ll)reach - i + 1;
        ll tmp = len;
        subv(tmp, 0);
        addv(res, tmp);
        i++;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi A(n+2), B(n+2);
        int i = 1;
        while(i <= n){
            cin >> A[i];
            i++;
        }
        i = 1;
        while(i <= n){
            cin >> B[i];
            i++;
        }
        vector<array<int,2>> f(n+2);
        build_f(n, A, B, f);
        ll ans = compute_ans(n, f);
        out(ans);
    }
    return 0;
}
