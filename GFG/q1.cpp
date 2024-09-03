#define ll long long 
class Solution { 
public: 
    int minRemaining(int n, vector<vector<int>> &boys, vector<vector<int>> &girls) { 
        vector<vector<int>> adja(n, vector<int>(n, 0)); 
        for (int i = 0; i < n; ++i) { 
            for (int j = 0; j < n; ++j) { 
                if (boys[i][0] < girls[j][0] && boys[i][1] < girls[j][1]) { 
                    adja[i][j] = 1; 
                } 
            } 
        } 
         
        function<bool(int, vector<int>&, vector<vector<int>>&, vector<bool>&)> dfs = & -> bool { 
            for (int v = 0; v < n; ++v) { 
                if (adja[u][v] && !dekhLiya[v]) { 
                    dekhLiya[v] = true; 
                    if (matching[v] == -1 || dfs(matching[v], matching, adja, dekhLiya)) { 
                        matching[v] = u; 
                        return true; 
                    } 
                } 
            } 
            return false; 
        }; 
 
        vector<int> matching(n, -1); 
        int maxi = 0; 
        for (int i = 0; i < n; ++i) { 
            vector<bool> dekhLiya(n, false); 
            if (dfs(i, matching, adja, dekhLiya)) { 
                ++maxi; 
            } 
        } 
 
        return n - maxi; 
    } 
};