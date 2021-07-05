// Leetcode: 773. Sliding Puzzle

class Solution {
public:
    vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

    vector<string> get(string s){			//确定0的位置，每次将相邻位置进行交换 
        vector<string> ret;
        int x = s.find("0");
        for(int y : neighbors[x]){
            swap(s[x], s[y]);
            ret.push_back(s);
            swap(s[x], s[y]);
        }
        return ret;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        int n = board.size();

        string initial;
        for(int i = 0; i < 2; ++i)
            for(int j = 0; j < 3; ++j)
                initial += char(board[i][j] + '0');
        
        if(initial == "123450")
            return 0;
        
        queue<pair<string, int>> q;			//记录每次矩阵的位置， status, step 
        q.emplace(initial, 0);
        unordered_set<string> seen = {initial};

        while(q.size()){
            auto [status, step] = q.front(); q.pop();
            for(auto&& next_status : get(status)){		
                if(next_status == "123450")
                    return step+1;
                if(!seen.count(next_status)){
                    seen.insert(next_status);
                    q.emplace(next_status, step+1);
                }
            }
        }
        return -1;
    }
};
