//树状数组Ⅱ 区间更新， 区间查询 

//∑ni = 1A[i] = ∑ni = 1 ∑ij = 1D[j];
//
//A[1]+A[2]+...+A[n]
//= (D[1]) + (D[1]+D[2]) + ... + (D[1]+D[2]+...+D[n]) 
//= n*D[1] + (n-1)*D[2] +... +D[n]
//= n * (D[1]+D[2]+...+D[n]) - (0*D[1]+1*D[2]+...+(n-1)*D[n])

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 50;

int tr1[N], tr2[N], a[N];
int n, m, l, r, d;
char c;

int lowbit(int x)
{
    return x & -x;
}

void update(int x, int c){
    int t = x-1;
    for(; x <= n; x += lowbit(x)){
        tr1[x] += c;
        tr2[x] += t * c;
    }
}

int query(int x){
    int ret = 0;
    int t = x;
    for(; x; x -= lowbit(x)){
        ret += tr1[x] * t - tr2[x];
    }
    return ret;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i){
        scanf("%d", a + i);
        update(i, a[i] - a[i-1]);
    }
    for(int i = 1; i <= m; ++i){
        getchar();
        scanf("%c", &c);
        if(c == 'Q'){
            scanf("%d%d", &l, &r);
            printf("%d\n", query(r) - query(l-1));
        }else if(c == 'C'){
            scanf("%d%d%d", &l, &r, &d);
            update(l, d);
            update(r+1, -d);
        }
    }
    return 0;
}



