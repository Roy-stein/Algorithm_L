#include <iostream>
#include <cstring>
#include <algorithm>
#include<set>
#include <vector>
#define ll long long
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;

const int N = 110;
int n, m;
int w[N][N];

ll calc(set<PII> q){
    vector<int> nums;
    for(auto p : q)
        nums.push_back(w[p.x][p.y]);
    sort(nums.begin(), nums.end());
    ll ret = 0;
    int len = nums.size();
    for(int i = 0; i < len; ++i)
        ret += abs(nums[i] - nums[len / 2]);
    return ret;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                scanf("%d", &w[i][j]);
        
        ll ret = 0;
        for (int i = 0; i <= n - i - 1; i ++ )
            for (int j = 0; j <= m - j - 1; j ++ ){
                ret += calc({{i, j}, {i, m - j - 1}, {n - i - 1, j}, {n - i - 1, m - j - 1}});
            }
        printf("%lld\n", ret);
    }
}
