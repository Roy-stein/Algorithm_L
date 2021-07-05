// Leetcode: 1239. Maximum Length of a Concatenated String with Unique Characters

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ret = 0;
        int n = arr.size();
        vector<int> masks = {0};
        for(string& s : arr){
            int mask = 0;
            for(char& c : s){
                int ch = c - 'a';
                if((mask >> ch) & 1){       //当前单词已存在重复
                    mask = 0;
                    break;
                }
                mask |= 1 << ch;
            }
            if(mask == 0)
                continue;
            for(int i = 0; i < masks.size(); ++i){
                int m = masks[i];
                if((m & mask) == 0){
                    masks.push_back(m | mask);  //更新所有可选集合
                    ret = max(ret, __builtin_popcount(m | mask));
                }
            }
        }
        return ret;
    }
};
