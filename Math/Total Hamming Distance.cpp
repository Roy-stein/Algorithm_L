//Total Hamming Distance

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ret = 0;
        int n = nums.size();
        for(int i = 30; i >= 0; --i){
            int tmp = 0;
            for(int num : nums){
                if(num >> i & 1)
                    ++tmp;
            }
            ret += tmp * (n-tmp);
        }
        return ret;
    }
};
