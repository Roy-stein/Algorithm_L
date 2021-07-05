// leetcode: permutation_No repeat

class Solution {
public:
    vector<string> ans;
    bool vis[15];
    void dfs(string tmp, string s){
        if(tmp.size() == s.size()){
            ans.push_back(tmp);
            return ;
        }
        for(int i = 0; i < s.size(); ++i){
            if(!vis[i]){
                if(i > 0 && !vis[i-1] && s[i] == s[i-1])
                    continue;
                vis[i] = 1;
                tmp.push_back(s[i]);
                dfs(tmp, s);
                tmp.pop_back();
                vis[i] = 0;
            }
        }
    }

    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        dfs("", s);
        return ans;
    }
};

class Solution {
public:
    bool nextPermutation(string& s){
        int i = s.size() - 2;
        while(i >= 0 && s[i] >= s[i+1]) --i;
        if(i < 0) return false;
        int j = s.size()-1;
        while(j >= 0 && s[j] <= s[i]) --j;
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        return true;
    }

    vector<string> permutation(string s) {
        vector<string> ret;
        sort(s.begin(), s.end());
        do{
            ret.push_back(s);
        }while(nextPermutation(s));
        return ret;
    }
};
