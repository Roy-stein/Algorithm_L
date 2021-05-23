#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e6+5;

int a[N], b[N], n, tmp;

//the first subsequence differs

int main(){
    vector<int> ret;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &tmp), a[tmp] = i;
    for (int i = 0; i < n; i ++ )
        scanf("%d", b+i), b[i] = a[b[i]];
    for (int i = 0; i < n; i ++ ){
        if(b[i] == 0){
            continue;
        }else if(ret.empty() || ret.back() < b[i]){
            ret.push_back(b[i]);
        }else{
            *lower_bound(ret.begin(), ret.end(), b[i]) = b[i];
        }
    }
    printf("%d", (int)ret.size());
}

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                if(nums1[i-1] == nums2[j-1])
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        return dp[n][m];
    }
};
