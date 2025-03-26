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

vi NGE(vi &v){
	vi nge(v.size());
	stack<int> st;

	for(int i = 0; i < v.size(); i++){
		while (!st.empty() && v[i] >= st.top() )
		{
			auto it = find(all(v),st.top());
			nge[it] = v[i];
			st.pop();
		}
		st.push(v[i]);
	}

	while (!st.empty())
	{
		auto it = find(all(v),st.top());
		nge[it] = -1;
		st.pop();
	}
	return nge;
}

int main(){
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		int n ; cin>>n;
		vi v(n);
		read(v);

		vi nge = NGE(v);
		for (auto &it: nge)
		{
			cout<<it<<" ";
		}
		cout<<endl;
		
		return 0;
}