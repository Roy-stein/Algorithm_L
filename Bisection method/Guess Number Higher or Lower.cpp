// Leetcode: 374. Guess Number Higher or Lower

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left < right) { // ѭ��ֱ���������Ҷ˵���ͬ
            int mid = left + (right - left) / 2; // ��ֹ����ʱ���
            if (guess(mid) <= 0) {
                right = mid; // �������� [left, mid] ��
            } else {
                left = mid + 1; // �������� [mid+1, right] ��
            }
        }
        // ��ʱ�� left == right��������Ϊһ���㣬��Ϊ��
        return left;
    }
};
