// Leetcode: 279. Perfect Squares

class Solution {
public:
    int numSquares(int n) {
        vector<int> nums;
        for(int i = 1; i * i <= n; ++i)
            nums.push_back(i*i);
        vector<int> dp(n+1, 0x3f);
        dp[0] = 0;
        for(int& num : nums){
            for(int i = num; i <= n; ++i){
                dp[i] = min(dp[i], dp[i-num] + 1);
            }
        }
        return dp[n];
    }
};

//math 
//四平方和定理证明了任意一个正整数都可以被表示为至多四个正整数的平方和。这给出了本题的答案的上界。
//同时四平方和定理包含了一个更强的结论：当且仅当 n != 4^k * (8m+7), n只能被表示为至多3个正整数的平方和 
//当 n == 4^k * (8m+7), n 只能被表示为4个正整数的平方和。此时我们可以直接返回 44 
class Solution {
public:
    bool isPerfectSquare(int n){
        for(int i = 1; i * i <= n; ++i)
            if(i*i == n)
                return true;
        return false;
    }

    bool checkAnswer(int n){
        while(n % 4 == 0){
            n /= 4;
        }
        return n % 8 == 7;
    }

    int numSquares(int n) {
        if(isPerfectSquare(n))
            return 1;
        if(checkAnswer(n))
            return 4;
        for(int i = 1; i * i <= n; ++i){
            int j = n - i*i;
            if(isPerfectSquare(j))
                return 2;
        }
        return 3;
    }
};
