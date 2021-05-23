class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> vc;
        while(n){
            vc.push_back(n % 10);
            n /= 10;
        }
        reverse(vc.begin(), vc.end());
        int pos = vc.size() - 1, len = pos;
        while(pos > 0 && vc[pos] <= vc[pos-1])
            --pos;
        reverse(vc.begin() + pos, vc.end());
        if(pos > 0){
            int start = pos;
            for(; start <= len; ++start)
                if(vc[start] > vc[pos-1]){
                    swap(vc[start], vc[pos-1]);
                    break;
                }
            long long ans = 0;
            for(int i = 0; i < vc.size(); ++i)
                ans = ans * 10 + vc[i];
            if(ans > INT_MAX)
                return -1;
            return ans;
        }else
            return -1;
    }
};
