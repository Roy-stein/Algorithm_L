class Solution {
public:
	//Binary Search
    bool check(vector<int>& bloomDay, int m, int n, int k, int mid){
       int count = 0, ret = 0;
        for(int i = 0; i < bloomDay.size(); ++i){
            if(bloomDay[i] <= mid){
                ++count;
            } else{
                count = 0;
            }

            if(count == k){
                ++ret;
                count = 0;
            }
        }
        return ret >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m*k > n)
            return -1;
        int l = 1, r = *max_element(bloomDay.begin(), bloomDay.end());
        int ret = 0;
        while(l < r){
            int mid = (l+r) / 2;
            // if(1)
            if(check(bloomDay, m, n, k, mid)){
                r = mid;
            }
            else
                l = mid+1;
        }
        return l;
    }
};
