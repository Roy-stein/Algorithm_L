// Leetcode: 877. Stone Game
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        //dp[i][j] ��ʾ�ӵ�i�ѵ���j��˫����ʯ�������� 
        for(int i = 0; i < n; ++i)
            dp[i][i] = piles[i];
        for(int i = n-2; i >= 0; --i)
            for(int j = i+1; j < n; ++j)
                dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1]);
        return dp[0][n-1] > 0;
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> dp(n, 0);
        for(int i = 0; i < n; ++i)
            dp[i] = piles[i];
        for(int i = n-2; i >= 0; --i)
            for(int j = i+1; j < n; ++j)
                dp[j] = max(piles[i] - dp[j], piles[j] - dp[j-1]);
        return dp[n-1] > 0;
    }
};
