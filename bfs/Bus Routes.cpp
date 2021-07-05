// Leetcode: 815. Bus Routes

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target)
            return 0;

        int n = routes.size();
        vector<vector<int>> edges(n, vector<int>(n, 0));
        unordered_map<int, vector<int>> rec;//每个site对应在哪些公交线路上
        for(int i = 0; i < n; ++i)
            for(auto& site : routes[i]){
                for(auto& j : rec[site]){
                    edges[i][j] = edges[j][i] = true;
                }
                rec[site].push_back(i);     //将i线路加入到site的映射中
            }
        
        vector<int> dis(n, -1);
        queue<int> q;
        for(auto& site : rec[source]){
            dis[site] = 1;              //每个轮次代表结点，表示做几轮公交车
            q.push(site);
        }

        while(q.size()){
            int x = q.front(); q.pop();
            for(int y = 0; y < n; ++y){
                if(edges[x][y] && dis[y] == -1){
                    dis[y] = dis[x] + 1;
                    q.push(y);
                }
            }
        }

        int ret = 0x3f3f3f3f;
        for(auto& site : rec[target]){
            if(dis[site] != -1)
                ret = min(ret, dis[site]);
        }
        if(ret == 0x3f3f3f3f)
            return -1;
        return ret;
    }
};
