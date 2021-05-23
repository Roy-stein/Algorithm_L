class Trie{
    public:
        const int L = 30;
        Trie* son[2] = {};
        int min = INT_MAX;

        void insert(int val){
            Trie* node = this;
            node->min = std::min(val, node->min);
            for(int i = L-1; i >= 0; --i){
                int bit = (val >> i) & 1;
                if(node->son[bit] == nullptr){
                    node->son[bit] = new Trie();
                }
                node = node->son[bit];
                node->min = std::min(val, node->min);
            }
        }

        int query(int val, int limit){
            Trie* node = this;
            if(node->min > limit)
                return -1;
            int ans = 0;
            for(int i = L-1; i >= 0; --i){
                int bit = (val >> i) & 1;
                if(node->son[bit ^ 1] != nullptr && node->son[bit ^ 1]->min <= limit){
                    ans |= 1 << i;
                    bit ^= 1;
                }
                node = node->son[bit];
            }
            return ans;
        }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ret;
        Trie* trie = new Trie();
        for(int num : nums)
            trie->insert(num);
        for(auto p : queries){
            ret.push_back(trie->query(p[0], p[1]));
        }
        return ret;
    }
};
