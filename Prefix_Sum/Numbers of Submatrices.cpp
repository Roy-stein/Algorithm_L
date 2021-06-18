// Subarray Sum Equals K
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, ret = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int num : nums){
            sum += num;
            if(mp.count(sum - k))
                ret += mp[sum-k];
            ++mp[sum];
        }
        return ret;
    }
};

// Number of Submatrices That Sum to Target
class Solution {
public:
    int subArraySum(vector<int>& nums, int k){
        unordered_map<int, int> mp;
        int ret = 0, sum = 0;
        mp[0] = 1;
        for(int num : nums){
            sum += num;
            if(mp.count(sum - k))
                ret += mp[sum - k];
            ++mp[sum];
        }
        return ret;
    }

    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int ret = 0;
        for(int i = 0; i < m; ++i){         //枚举上边界
            vector<int> sums(n, 0);
            for(int j = i; j < m; ++j){      //枚举下边界
                for(int k = 0; k < n; ++k)
                    sums[k] += matrix[j][k];
                ret += subArraySum(sums, target);
            }
        }
        return ret;
    }
};
