// coded by Cocane

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int a, b;
        ll x, y;
        cin >> a >> b >> x >> y;

        const ll INF = (ll)4e18;
        // we'll explore states 0..200
        int N = 201;
        vector<ll> dist(N, INF);
        // max‐heap storing { -dist, node }
        priority_queue<pair<ll,int>> pq;

        dist[a] = 0;
        pq.push({0, a});  // -0 == 0

        while(!pq.empty()){
            auto [negd, u] = pq.top(); 
            pq.pop();
            ll d = -negd;
            if(d > dist[u]) continue;
            if(u == b) break;  // once we pop b at minimal dist, we're done

            // op1: u -> u+1
            if(u+1 < N){
                ll nd = d + x;
                if(nd < dist[u+1]){
                    dist[u+1] = nd;
                    pq.push({-nd, u+1});
                }
            }
            // op2: u -> u^1
            int v = u ^ 1;
            {
                ll nd = d + y;
                if(nd < dist[v]){
                    dist[v] = nd;
                    pq.push({-nd, v});
                }
            }
        }

        if(dist[b] >= INF/2) 
            cout << -1 << "\n";
        else 
            cout << dist[b] << "\n";
    }

    return 0;
}
