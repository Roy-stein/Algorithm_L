// Leetcode: 483. Smallest Good Base

class Solution {
public:
//假设正整数 n 在 (k≥2) 进制下的所有数位都为1，且位数为 m + 1，那么有：
//n = k^0 + k^1 + k^2 + ... + k^m
//结论1: m<log2N
//结论2: k=n的1/m次方
    string smallestGoodBase(string n) {
        long nVal = stol(n);
        int mMax = floor(log(nVal) / log(2));
        for(int m = mMax; m > 1; --m){
            int k = pow(nVal, 1.0 / m);
            long mul = 1, sum = 1;
            for(int i = 0; i < m; ++i){
                mul *= k;
                sum += mul;
            }
            if(sum == nVal)
                return to_string(k);
        }
        return to_string(nVal-1);
    }
};
