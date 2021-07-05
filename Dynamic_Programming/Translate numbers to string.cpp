// 剑指offer 46. Translate numbers to string 

class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            dp[i] = dp[i-1];        //每一层状态与上一层有关
            if(s[i-2] != '1' && s[i-2] != '2') continue;
            if(s[i-2] == '2' && s[i-1] > '5') continue;
            dp[i] += dp[i-2];
        }
        return dp[n];
    }
};

class Solution {
public:
    int translateNum(int num) {
        if(num <= 9 && num >= 0)
            return 1;
        if(num % 100 >= 10 && num % 100 <= 25)
            return translateNum(num/10) + translateNum(num/100);
        return translateNum(num/10);
    }
};
