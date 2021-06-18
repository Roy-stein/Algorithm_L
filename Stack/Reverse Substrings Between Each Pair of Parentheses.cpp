// LC: 1190. Reverse Substrings Between Each Pair of Parentheses
class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> stk;
        string str = "";
        for(char& c : s){
            if(c == '('){
                stk.push_back(str);
                str.clear();
            }else if(c == ')'){
                reverse(str.begin(), str.end());
                str = stk.back() + str; 
                stk.pop_back();
            }else{
                str += c;
            }
        }
        return str;
    }
};

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> pair(n);
        vector<int> stk;
        for(int i = 0; i < n; ++i){
            if(s[i] == '('){
                stk.push_back(i);
            }else if(s[i] == ')'){
                int j = stk.back();
                stk.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }

        int step = 1, index = 0;
        string ans = "";
        while(index < n){
            if(s[index] == '(' || s[index] == ')'){
                index = pair[index];
                step = -step;
            }else{
                ans.push_back(s[index]);
            }
            index += step;
        }
        return ans;
    }
};
