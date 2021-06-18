// Leetcode: 879. Profitable Schemes

class Solution {
public: 
    // 0/1±³°ü¶þÎ¬
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<long long>> dp(n+1, vector<long long>(minProfit+1, 0));
        int m = group.size(), mod = (int)1e9+7;
        for(int i = 0; i <= n; ++i)
            dp[i][0] = 1;
        
        for(int i = 0; i < m; ++i){
            int persons = group[i], earns = profit[i];
            for(int j = n; j >= persons; --j)
                for(int k = minProfit; k >= 0; --k)
                    dp[j][k] = (dp[j][k] + dp[j - persons][max(0, k - earns)]) % mod;
        }
        return dp[n][minProfit];
    }
};
