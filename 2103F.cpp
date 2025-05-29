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

const int MAXIM = 1e5 + 5;
ll sV[4 * MAXIM], sL[4 * MAXIM];
int n;

void APPLYING(int idx, ll val) {
	sV[idx] = max(sV[idx], val);
	sL[idx] = max(sL[idx], val);
}

void push(int idx) {
	if(sL[idx]) {
		APPLYING(idx*2, sL[idx]);
		APPLYING(idx*2+1, sL[idx]);
		sL[idx] = 0;
	}
}

void UPDATTE(int idx, int l, int r, int ql, int qr, ll val) {
	if(qr < l || r < ql) return;
	if(ql <= l && r <= qr) {
		APPLYING(idx, val);
		return;
	}
	push(idx);
	int mid = (l + r) / 2;
	UPDATTE(idx*2, l, mid, ql, qr, val);
	UPDATTE(idx*2+1, mid+1, r, ql, qr, val);
	sV[idx] = max(sV[idx*2], sV[idx*2+1]);
}

void COLLECTINNG(int idx, int l, int r, vll &ans) {
	if(l == r) {
		ans[l] = sV[idx];
		return;
	}
	push(idx);
	int mid = (l + r) / 2;
	COLLECTINNG(idx*2, l, mid, ans);
	COLLECTINNG(idx*2+1, mid+1, r, ans);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> n >> k;
		vll a(n+1);
		for1(i, n) cin >> a[i];

		int sz = 4 * n;
		for1(i, sz) sV[i] = sL[i] = 0;

		ll mask = (k == 64 ? -1LL : ((1LL << k) - 1));

		vector<pair<ll, int>> prev, cur;
		prev.reserve(k+2);
		cur.reserve(k+2);

		for1(r, n){
			cur.clear();
			cur.pb({a[r], r});

			for(auto &[st, L] : prev){
				ll ns = ~(st | a[r]) & mask;
				bool f = false;
				for(auto &[pst, pL] : cur){
					if(pst == ns){
						pL = min(pL, L);
						f = true;
						break;
					}
				}
				if(!f) cur.pb({ns, L});
			}

			for(auto &[st, L] : cur){
				UPDATTE(1, 1, n, L, r, st);
			}

			swap(prev, cur);
		}

		vll ans(n+1);
		COLLECTINNG(1, 1, n, ans);
		for1(i, n) cout << ans[i] << " \n"[i==n];
	}
	return 0;
}
