// Leetcode: 1449. Form Largest Integer With Digits That Add up to Target

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        int n = cost.size();
        vector<string> dp(target+1, "#");   //��ֹ�������гɱ�������target���
        dp[0] = "";
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= target; ++j){
                if(j >= cost[i-1] && dp[j-cost[i-1]] != "#"){
                    //  ��ǰ��ӣ���Ϊ��ֵ��������
                    dp[j] = ComparingString(dp[j], to_string(i) + dp[j-cost[i-1]]);
                }
            }
        }
        return dp[target] == "#" ? "0" : dp[target];
    }
private:
    //string ���ʹ�������Ҫ���const����
    string ComparingString(const string& A, const string& B){
        int m = A.size(), n = B.size();
        if(m == n) return max(A, B);
        return m > n ? A : B;
    }
};
