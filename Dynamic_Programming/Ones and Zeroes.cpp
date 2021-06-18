// Leetcode: 474. Ones and Zeroes
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int>> dp(m+1, vector<int>(n+1));
		//dp[m][n] represents m as zero and n as one end maximum number 
        for(const string& s : strs){
            int zeros = 0, ones = 0;
            for(const char& c : s){
                if(c == '0')
                    ++zeros;
                else
                    ++ones;
            }
            for(int i = m; i >= zeros; --i)
                for(int j = n; j >= ones; --j){
                    dp[i][j] = max(dp[i][j], 1 + dp[i-zeros][j-ones]);
                }
            }
        return dp[m][n];
    }
};
