#include<cstdio>
using namespace std;

const int M = 2e5 + 10, B = M/2, N=110;
bool f[N][M];
int w[N];
int n, m;

int main(){
    scanf("%d", &n);
    f[0][0+B] = true;
    for(int i = 1; i <= n; ++i) scanf("%d", &w[i]), m += w[i];
    for(int i = 1; i <= n; ++i){
        for(int j = -m; j <= m; ++j){
            f[i][j+B] = f[i-1][j+B];
            if(j-w[i] >= -m) f[i][j+B] |= f[i-1][j-w[i]+B];
            if(j+w[i] <= m) f[i][j+B] |= f[i-1][j+w[i]+B];
        }
    }
    int ret = 0;
    for(int i = 1; i <= m; ++i)
        if(f[n][i+B])
            ++ret;
    printf("%d", ret);
}
