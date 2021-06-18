class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int count = 0;
        int ret = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i = 0; i < n; ++i){
            if(nums[i] == 1)
                ++count;
            else
                --count;
            if(mp.count(count)){
                int pre = mp[count];
                ret = max(ret, i - pre);
            }else{
                mp[count] = i;
            }
        }
        return ret;
    }
};
