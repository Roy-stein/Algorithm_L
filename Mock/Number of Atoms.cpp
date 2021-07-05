// Leetcode:726. Number of Atoms

class Solution {
public:
    string countOfAtoms(string formula) {
        int i = 0, n = formula.size();

        auto parseAtom = [&]() -> string {
            string atom;
            atom += formula[i++];
            while(i < n && islower(formula[i])){
                atom += formula[i++];
            }
            return atom;
        };

        auto parseNum = [&]() -> int {
            if(i == n || !isdigit(formula[i]))
                return 1;   //末尾无数字，默认为1
            
            int num = 0;
            while(i < n && isdigit(formula[i])){
                num = num * 10 + int(formula[i++] - '0');
            }
            return num;
        };

        vector<unordered_map<string, int>> vc;
        vc.push_back({});   //将空的哈希表压入栈，准备统计括号内的原子数目
        while(i < n){
            char ch = formula[i];
            if(ch == '('){
                ++i;
                vc.push_back({});
            }else if(ch == ')'){
                ++i;
                int num = parseNum();    //括号右侧的数字
                auto atomNum = vc.back(); vc.pop_back();
                //弹出括号内原子数量
                for(auto [atom, v] : atomNum){
                    vc.back()[atom] += v * num;
                    //将括号内的原子数量乘上num加到上一层的原子数
                }
            } else{
                string atom = parseAtom();
                int num = parseNum();
                vc.back()[atom] += num; //统计原子数目
            }
        }
        auto &atomNum = vc.back();
        vector<pair<string, int>> pairs;
        for(auto [atom, v] : atomNum){
            pairs.emplace_back(atom, v);
        }
        sort(pairs.begin(), pairs.end());
        
        string ret;
        for(auto& p : pairs){
            ret += p.first;
            if(p.second > 1)
                ret += to_string(p.second);
        }
        return ret;
    }
};
