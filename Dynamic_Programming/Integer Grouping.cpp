#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5050;
int a[N];
int dp[N][N];       // i 表示当前为第i个数, j 表示当前为第j个分组
int n, k;

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i)
        scanf("%d", a+i);
    sort(a+1, a+1+n);
    for(int i=1,u=1; i <= n; ++i){
        while(a[i] - a[u] > 5) ++u;
        for(int j = 1; j <= k; ++j){
            dp[i][j] = max(dp[i-1][j], dp[u-1][j-1] + (i-u+1));
        }
    }
    printf("%d", dp[n][k]);
}
