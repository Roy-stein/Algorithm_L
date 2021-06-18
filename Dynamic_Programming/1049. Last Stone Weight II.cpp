// Leetcode 1049. Last Stone Weight II
class Solution {
public:
    //取所有负stones[i]和为neg
    // Σk*stones[i] = (sum - neg) - neg = sum - 2 * neg
    //题意转换为取负数和最大的0/1背包问题
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int diff = sum / 2;
        vector<int> dp(diff + 1);
        for(int& stone : stones){
            for(int j = diff; j >= stone; --j)
                dp[j] = max(dp[j], dp[j-stone] + stone);
        }
        return sum - 2 * dp[diff];
    }
};
