class Solution {
public:
	//Binary Search & dfs
    bool dfs(vector<int>& jobs, vector<int>& person, int k, int n, int cur, int Time){
        if(cur == n){
            return true;
        }
        for(int i = 0; i < k; ++i){
            if(person[i] + jobs[cur] <= Time){
                person[i] += jobs[cur];
                if(dfs(jobs, person, k, n, cur+1, Time))
                    return true;
                person[i] -= jobs[cur];
            }
            if(person[i] == 0 || person[i] + jobs[cur] == Time)
               break;
        }
        return false;
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin(), jobs.end(), greater<int>());
        int n = jobs.size();
        int l = 1, r = accumulate(jobs.begin(), jobs.end(), 0);
        while(l < r){
            int mid = (l+r)/2;
            vector<int> person(k, 0);
            if(dfs(jobs, person, k, n, 0, mid))
                r = mid;
            else
                l = mid+1;
        }
        return l;
    }
};
