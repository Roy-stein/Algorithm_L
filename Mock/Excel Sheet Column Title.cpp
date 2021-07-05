// Leetcode: 168. Excel Sheet Column Title

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ret;
        while(columnNumber){
            --columnNumber;						//下标从1开始，所以每次减1等价于[1,26]转换至[0, 25]; 
            ret.push_back('A' + columnNumber%26);
            columnNumber /= 26;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
