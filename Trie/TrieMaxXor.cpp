class Solution {
public:
    int son[1000050][2], idx;
    void insert(int x){
        int p = 0;
        for(int i = 30; i >= 0; --i){
            int u = x >> i & 1;
            if(!son[p][u]){
                son[p][u] = ++idx;
            }
            p = son[p][u];
        }
    }

    int query(int x){
        int ret = 0, p = 0;
        for(int i = 30; i >= 0; --i){
            int u = x >> i & 1;
            if(son[p][!u])
                ret = ret*2+1, p = son[p][!u];
            else
                ret = ret*2, p = son[p][u];
        }
        return ret;
    }

    int findMaximumXOR(vector<int>& nums) {
        int x = 0, n = nums.size();
        for(int i = 1; i < n; ++i){
            insert(nums[i-1]);
            x = max(x, query(nums[i]));
        }
        return x;
    }
};
