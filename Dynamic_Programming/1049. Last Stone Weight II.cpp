// Leetcode 1049. Last Stone Weight II
class Solution {
public:
    //ȡ���и�stones[i]��Ϊneg
    // ��k*stones[i] = (sum - neg) - neg = sum - 2 * neg
    //����ת��Ϊȡ����������0/1��������
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
