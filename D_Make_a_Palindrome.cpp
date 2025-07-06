#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define dl double

#define forn(i, n) for(int i = 0; i < (n); ++i)
#define for1(i, n) for(int i = 1; i <= (n); ++i)
#define foru(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ppb pop_back
#define read(x) cin >> (x)
#define out(x) cout << (x)
#define yn(x) cout << ((x) ? "YES\n" : "NO\n")

// Fenwick tree for frequencies of values [1..n]:
struct Fenwick {
    int n;
    vector<int> f;
    Fenwick(int _n): n(_n), f(n+1,0) {}
    void update(int i,int v){ for(; i<=n; i+=i&-i) f[i]+=v; }
    int query(int i) const { int s=0; for(; i>0; i-=i&-i) s+=f[i]; return s; }
    // find smallest `v` so that query(v) >= k
    int kth(int k) const {
        int pos=0, sum=0;
        for(int pw=1<<__lg(n); pw>0; pw>>=1){
            if(pos+pw<=n && sum+f[pos+pw]<k){
                sum += f[pos+pw];
                pos  += pw;
            }
        }
        return pos+1;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; read(T);
    while(T--){
        int n,k;
        read(n); read(k);
        vi a(n+1);
        for1(i,n) read(a[i]);

        // Quick YES if already palindrome or k==1:
        bool pal=true;
        for(int i=1; i<=n/2; i++){
            if(a[i]!=a[n-i+1]){ pal=false; break; }
        }
        if(pal || k==1){
            yn(true);
            continue;
        }

        // Build Fenwick over values [1..n]
        Fenwick fenw(n);
        for1(i,n) fenw.update(a[i],1);

        // Build doubly‐linked list over positions 1..n
        vector<int> prv(n+2), nxt(n+2);
        for(int i=0;i<=n+1;i++){
            prv[i]=i-1;
            nxt[i]=i+1;
        }
        int head = 1, tail = n, len = n;

        // For each value v, keep a set of *current* positions
        vector< set<int> > pos(n+1);
        for1(i,n) pos[a[i]].insert(i);

        // Helper to unlink index i from the linked list:
        auto unlink_idx = [&](int i){
            int L = prv[i], R = nxt[i];
            nxt[L] = R;
            prv[R] = L;
            if(head==i) head = R;
            if(tail==i) tail = L;
            len--;
        };

        // Helper to check if current list is palindrome (O(len)):
        auto is_pal = [&](){
            int L = head, R = tail;
            while(L < R){
                if(a[L] != a[R]) return false;
                L = nxt[L];
                R = prv[R];
            }
            return true;
        };

        bool ok = false;
        // We *must* stop as soon as we reach a palindrome (we don't have to do more deletions!)
        if(is_pal()){
            ok = true;
        } else {
            // Otherwise, simulate deletions
            while(len >= k){
                // find the global k-th smallest value
                int val = fenw.kth(k);
                // pick one occurrence of val
                int idx = *pos[val].begin();
                // remove it
                pos[val].erase(idx);
                fenw.update(val,-1);
                unlink_idx(idx);

                // check if we've now formed a palindrome
                if(is_pal()){
                    ok = true;
                    break;
                }
            }
            // if we exited loop without early-pal, and not ok yet:
            if(!ok){
                ok = is_pal();
            }
        }

        yn(ok);
    }

    return 0;
}
// coded by Cocane
