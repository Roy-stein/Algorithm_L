#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N =40010;
int row[N], col[N];
int n, m, k;
typedef long long LL;

LL count(int k, int arr[], int len){        //计算有多少个长度为k的连续1序列
    LL ret = 0;
    LL cur = 0;
    for (int i = 1; i <= len; i ++ ){
        if(arr[i])
            ++ cur;
        else{
            if(cur >= k) ret += cur - k + 1;
            cur = 0;
        }
    }
    if(cur >= k)
        ret += cur - k + 1;
    return ret;
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; ++i)
        scanf("%d", row + i);
    for(int j = 1; j <= m; ++j)
        scanf("%d", col + j);
    LL ans = 0;
    for(int i = 1; i <= k && i <= 40000; ++i){
        if(k % i == 0){
            int x = i, y = k / i;
            LL tx = count(x, row, n), ty = count(y, col, m);    //获得行与列的连续序列个数相乘得到矩形数目
            // printf("%lld %lld\n", tx, ty);
            ans += tx * ty;
        }
    }
    printf("%lld", ans);
    return 0;
}

