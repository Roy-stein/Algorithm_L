// Leetcode: 168. Excel Sheet Column Title

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ret;
        while(columnNumber){
            --columnNumber;						//�±��1��ʼ������ÿ�μ�1�ȼ���[1,26]ת����[0, 25]; 
            ret.push_back('A' + columnNumber%26);
            columnNumber /= 26;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
