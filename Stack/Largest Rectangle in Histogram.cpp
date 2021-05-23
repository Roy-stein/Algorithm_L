// Largest Rectangle in Histogram
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> stk;
        vector<int> l(n, 0), r(n, n);
        for(int i = 0; i < n; ++i){
            while(stk.size() && heights[stk.back()] >= heights[i]){
                r[stk.back()] = i;
                stk.pop_back();
            }
            l[i] = stk.empty() ? -1 : stk.back();
            stk.push_back(i);
        }
        int ret = 0;
        for(int i = 0; i < n; ++i){
            ret = max(ret, heights[i] * (r[i]-l[i]-1));
        }
        return ret;
    }
};
