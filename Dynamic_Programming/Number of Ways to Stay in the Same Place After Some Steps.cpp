//Number of Ways to Stay in the Same Place After Some Steps

class Solution {
public:
    int numWays(int steps, int arrLen) {
        int mod = 1000000007;
        int MaxL = min(arrLen-1, steps+1);
        vector<vector<int>> dp(steps+1, vector<int>(MaxL+1));
        //dp[i][j]  means after i steps the numbers of j position
        dp[0][0] = 1;
        for(int i = 1; i <= steps; ++i)
            for(int j = 0; j <= MaxL; ++j){
                dp[i][j] = dp[i-1][j];
                if(j-1 >= 0){
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
                }
                if(j+1 <= MaxL){
                    dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % mod;
                }
            }
        return dp[steps][0];
    }
};

class Solution {
public:
    int numWays(int steps, int arrLen) {
        int mod = 1000000007;
        int MaxL = min(arrLen-1, steps+1);
        vector<int> dp(MaxL+1);
        //dp[i] the numbers of j position
        dp[0] = 1;
        for(int i = 1; i <= steps; ++i){
            vector<int> nextDp(MaxL+1);
            for(int j = 0; j <= MaxL; ++j){
                nextDp[j] = dp[j]; 
                if(j-1 >= 0){
                    nextDp[j] = (nextDp[j] + dp[j-1]) % mod;
                }
                if(j+1 <= MaxL){
                    nextDp[j] = (nextDp[j] + dp[j+1]) % mod;
                }
            }
            dp = nextDp;
        }
        return dp[0];
    }
};
