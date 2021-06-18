// Make the XOR of All Segments Equal to Zero
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        int f[2000][1024];
        memset(f, 0x3f, sizeof f);
        int v = 0x3f3f3f3f;
        for(int i = 0; i < k; i++){
            int cnt = 0;
            unordered_map<int, int> mp;
            for(int j = i; j < n; j += k){
                mp[nums[j]]++;
                cnt++;
            }
            if(i == 0){
                for(int x = 0; x < 1024; x++){
                    f[0][x] = cnt - mp[x];
                    v = min(v, f[0][x]);
                }
            }else{
                int k = v;
                v = 0x3f3f3f3f;
                for(int x = 0; x < 1024; x++){
                    f[i][x] = k + cnt;
                    for(auto &m : mp){
                        f[i][x] = min(f[i][x], f[i - 1][x ^ m.first] + cnt - m.second);
                    }
                    v = min(v, f[i][x]);
                }
            }
        }
        return f[k - 1][0];
    }
};
