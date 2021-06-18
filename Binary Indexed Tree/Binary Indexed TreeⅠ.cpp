// 树状数组Ⅰ 区间修改， 单点查询 
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 50;
int tr[N], a[N];
int n, m;
int l, r , d;
char c;

int lowbit(int x){
    return x & (-x);
}

void update(int x, int c){
    for(; x <= n; x += lowbit(x)){
        tr[x] += c;
    }
}

int query(int x){
    int ret = 0;
    for(; x; x -= lowbit(x)){
        ret += tr[x];
    }
    return ret;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i){
        scanf("%d", a + i);
        update(i, a[i] - a[i-1]);        //差分
    }
    for(int i = 1; i <= m; ++i){
        getchar();
        scanf("%c", &c);
        if(c == 'Q'){
            scanf("%d", &d);
            printf("%d\n", query(d));
        }else if(c == 'C'){
            scanf("%d%d%d", &l, &r, &d);
            update(l, d);
            update(r+1, -d);
        }
    }
    return 0;
}
