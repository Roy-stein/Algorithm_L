#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 205;
int a[N][N];
int w[N], dp[N][N];
int n, m, k;

int main(){
    cin >> n >> k >> m;
    for(int i = 1; i <= m; ++i)
        cin >> w[i];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >>a[i][j];
    if(m == 1){
        cout << 0;
        return 0;
    }
    memset(dp, -0x3f, sizeof(dp));
    dp[1][0] = 0;
    for(int i = 1; i <= m; ++i){
        for(int j = 0; j <= k; ++j){
            for(int u = 1; u < i; ++u)
                if(j >= i - u - 1)
                     // ��ȻҪɾj����,�����ȰѺ���[u+1,i-1]��ɾ��,������ɾ��i-1-u����
                    // Ȼ������ǰ��[0,u]��ɾj-(i-1-u)����,��ʱk���i���ٽ�,�ɼӹ���w[a[u]][a[j]]
                    dp[i][j] = max(dp[i][j], dp[u][j-(i-u-1)] + a[w[u]][w[i]]);
        }
    }
    int ret = -0x3f3f3f3f;
    for(int i = 0; i <= k; ++i){
        ret = max(ret, dp[m][i]);
    }
    cout << ret;
}
