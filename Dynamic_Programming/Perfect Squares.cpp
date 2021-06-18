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
//��ƽ���Ͷ���֤��������һ�������������Ա���ʾΪ�����ĸ���������ƽ���͡�������˱���Ĵ𰸵��Ͻ硣
//ͬʱ��ƽ���Ͷ��������һ����ǿ�Ľ��ۣ����ҽ��� n != 4^k * (8m+7), nֻ�ܱ���ʾΪ����3����������ƽ���� 
//�� n == 4^k * (8m+7), n ֻ�ܱ���ʾΪ4����������ƽ���͡���ʱ���ǿ���ֱ�ӷ��� 44 
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
