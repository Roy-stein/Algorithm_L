class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> stk;
        vector<int> ret(n, -1);
        for(int i = 0; i < 2 * n; ++i){
            while(stk.size() && nums[stk.back()] < nums[i % n]){
                ret[stk.back()] = nums[i % n];
                stk.pop_back();
            }
            if(i < n)
                stk.push_back(i);
        }
        return ret;
    }
};
