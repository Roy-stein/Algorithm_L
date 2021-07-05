// Leetcode: 909. Snakes and Ladders

class Solution {
public:
    pair<int, int> id2tr(int id, int n){
        int r = (id-1) / n, c = (id-1) % n;
        if(r % 2 == 1){
            c = n - 1 - c;
        }
        return {n-r-1, c};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<pair<int, int>> q; // index, step
        vector<int> vis(n*n+1);
        q.emplace(1, 0);

        while(q.size()){
            auto p = q.front(); q.pop();

            for(int i = 1; i <= 6; ++i){
                int nxt = p.first + i;
                if(nxt > n*n)
                    break;
                auto [x, y] = id2tr(nxt, n);
                if(board[x][y] > 0){
                    nxt = board[x][y];
                }
                if(nxt == n * n){
                    return p.second + 1;
                }

                if(!vis[nxt]){
                    vis[nxt] = 1;
                    q.emplace(nxt, p.second+1);
                }
            }
        }
        return -1;
    }
};
