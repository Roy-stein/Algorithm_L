// Leetcode: 494. Target Sum

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int diff = sum - target;
        if(diff < 0 || diff & 1)
            return 0;
        diff /= 2;
        vector<int> dp(diff+1, 0);  //在数组取若干元素使和为diff的组合
        dp[0] = 1;
        for(int& num : nums){
            for(int i = diff; i >= num; --i)
                dp[i] += dp[i-num]; //选or不选
        }
        return dp[diff];
    }
};
