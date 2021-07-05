// Leetcode: 149. Max Points on a Line 

class Solution {
public:
    int gcd(int x, int y){
        return y == 0 ? x : gcd(y, x % y);
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2)
            return n;
        int ret = 0;
        //点斜式保存直线 
        for(int i = 0; i < n; ++i){
            unordered_map<int, int> mp;			//利用分子式保存斜率 
            int maxn = 0;
            for(int j = i+1; j < n; ++j){
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                if(x == 0) y = 1;				//排除斜率为0或不存在 
                else if(y == 0) x = 1;
                else{
                    if(y < 0){
                        x = -x; y = -y;
                    }
                    int _gcd = gcd(abs(x), abs(y));//化为最简分数 
                    x /= _gcd; y /= _gcd;
                }
                mp[y + x * 20001]++;
            }
            for(auto[_, num] : mp){
                maxn = max(maxn, num+1);
            }
            ret = max(maxn, ret);
        }
        return ret;
    }
};
