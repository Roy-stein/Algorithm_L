// Leetcode: 752. Open the Lock

class Solution {
public:
    char get_prev(char c){
        return c == '0' ? '9' : c-1;
    }

    char get_next(char c){
        return c == '9' ? '0' : c+1;
    }

    vector<string> get_(string s){
        vector<string> ret;
        for(int i = 0; i < 4; ++i){
            char c = s[i];
            s[i] = get_prev(c); //获得每一个轮盘下一转和上一转的结果
            ret.push_back(s);
            s[i] = get_next(c);
            ret.push_back(s);
            s[i] = c;
        }
        return ret;
    }

    int openLock(vector<string>& deadends, string target) {
        if(target == "0000")
            return 0;
        
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if(dead.count("0000"))
            return -1;
        
        unordered_set<string> seen;
        queue<pair<string, int>> q;
        seen.insert("0000");
        q.push(make_pair("0000", 0));

        while(q.size()){
            auto [status, step] = q.front();
            q.pop();

            for(auto&& p : get_(status)){
                if(p == target)
                    return step + 1;

                if(!seen.count(p) && !dead.count(p)){
                    q.emplace(make_pair(p, step+1));
                    seen.insert(move(p));
                }
            }
        }
        return -1;
    }
};
