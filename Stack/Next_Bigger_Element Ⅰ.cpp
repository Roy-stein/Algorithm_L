class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> stk;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums2.size(); ++i){
            while(stk.size() && stk.back() < nums2[i]){
                mp[stk.back()] = nums2[i];
                stk.pop_back();
            }
            stk.push_back(nums2[i]);
        }
        vector<int> ret;
        for(int num : nums1){
            if(mp.count(num))
                ret.push_back(mp[num]);
            else
                ret.push_back(-1);
        }
        return ret;
    }
};
