//lengthOfLIS
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ret;
        for(int x : nums){
            if(ret.empty() || x > ret.back())
                ret.push_back(x);
            else{
                *lower_bound(ret.begin(), ret.end(), x) = x;
            }
        }
        return ret.size();
    }
};
