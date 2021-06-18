// Continuous Subarray Sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;
        int sum = 0;
        for(int& num : nums){
            sum += num;
            if(st.count(sum % k))
                return true;
            st.insert((sum - num) % k);
        }
        return false;
    }
};
