// Leetcode: LCP 07. ������Ϣ


// BFS�ⷨ 
class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<int> nums(n, 0);
        queue<pair<int, int>> q;
        unordered_map<int, vector<int>> edges;
        for(auto p : relation)
            edges[p[0]].push_back(p[1]);
        q.emplace(0, 0);
        
        while(q.size()){
            auto[pos, step] = q.front(); q.pop();
            if(step == k)
                break;
            for(int v : edges[pos]){
                if(step == k-1)				//��step�����k-1��ʱ����ʾ��ʱ�Ѿ�����k�� 
                    nums[v]++;
                q.emplace(v, step+1);
            }
        }
        return nums[n-1];
    }
};

// DP�ⷨ���ռ临�Ӷ�O(nk)
class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> dp(k+1, vector<int>(n, 0));
        dp[0][0] = 1;
        for(int i = 0; i < k; ++i){
            for(auto p : relation){
                int src = p[0], end = p[1];
                dp[i+1][end] += dp[i][src];
            }
        }
        return dp[k][n-1];
    }
};

// DP�ⷨ���ռ临�Ӷ�o(n)
class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 0; i < k; ++i){
            vector<int> next(n, 0);
            for(auto p : relation){
                int src = p[0], end = p[1];
                next[end] += dp[src];
            }
            dp = next;
        }
        return dp[n-1];
    }
}; 
