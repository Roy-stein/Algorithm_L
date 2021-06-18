// Leetcode: 483. Smallest Good Base

class Solution {
public:
//���������� n �� (k��2) �����µ�������λ��Ϊ1����λ��Ϊ m + 1����ô�У�
//n = k^0 + k^1 + k^2 + ... + k^m
//����1: m<log2N
//����2: k=n��1/m�η�
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
