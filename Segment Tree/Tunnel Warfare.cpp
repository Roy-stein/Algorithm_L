 // HDU 1540 Tunnel Warfare（最长连续区间+单点修改）

#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
#include<cmath>
#include<stack>
#include<string>
 
const int maxn = 5e4 + 5;
const int mod = 10007;
const int inf = 1e9;
const long long onf = 1e18;
#define me(a, b) memset(a,b,sizeof(a))
#define lowbit(x) x&(-x)
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI 3.14159265358979323846
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int ls[maxn << 2], rs[maxn << 2], sum[maxn << 2];
///sum表示区间最长连续序列，ls表示从左端点开始最长连续前缀，rs表示从r开始最长后缀
int n, m;


void push_up(int l, int r, int rt){
    int mid = (l+r) >> 1;
    ls[rt] = ls[rt << 1];
    if(ls[rt << 1] == mid - l + 1)            //要是左区间最长长度等于左区间长度，那么区间最长前缀长度要加上儿子右区间的前缀长度
        ls[rt] += ls[rt << 1 | 1];
    rs[rt] = rs[rt << 1 | 1];
    if(rs[rt << 1 | 1] == r - mid)            //与上面情况一致
        rs[rt] += rs[rt << 1];
    sum[rt] = max(ls[rt], rs[rt]);          //左区间右区间最长连续长度
    sum[rt] = max(sum[rt], max(sum[rt<<1], sum[rt << 1 | 1]));    //左右儿子区间的长度
    sum[rt] = max(sum[rt], rs[rt << 1] + ls[rt << 1 | 1]);        //左区间最长后缀和右区间最长前缀， 即最长连续区间在中间
}
 
void push_date(int pos, int x, int l, int r, int rt){
    sum[rt] = ls[rt] = rs[rt] = 0;
    if(l == r){
        sum[rt] = ls[rt] = rs[rt] = x;
        return ;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid){
        push_date(pos, x, lson);
    }else{
        push_date(pos, x, rson);
    }
    push_up(l, r, rt);
}

// void build(int l, int r, int rt) {
//     if (l == r) {
//         ls[rt] = rs[rt] = sum[rt] = 1;///初始化所有点都没有被破坏
//         return;
//     }
//     int mid = (l + r) >> 1;
//     build(lson);
//     build(rson);
//     push_up(l, r, rt);
// }

void build(int l, int r, int rt){
    if(l == r){
        sum[rt] = ls[rt] = rs[rt] = 1;    //初始化所有点未被摧毁
        return ;
    }
    int mid = (l+r) >> 1;
    build(lson);
    build(rson);
    push_up(l, r, rt);
}



int query(int pos, int l, int r, int rt){
    if(l == r){
        return sum[rt];
    }
    int mid = (l+r) >> 1;
    if(pos <= mid){
        if(pos >= mid - rs[rt << 1] + 1){      //如果pos在左孩子的最长后缀中，
            return ls[rt << 1 | 1] + rs[rt << 1]; //最长区间就是左孩子的最长后缀加上右孩子的最长前缀（左孩子的最长后缀和右孩子的最长前缀是连着的）
        } else{
            return query(pos, lson);            //否则继续往下找
        }
    } else{
        if(pos <= mid + ls[rt << 1 | 1]){      //如果pos在右孩子的最长前缀中
            return ls[rt << 1 | 1] + rs[rt << 1]; //最长区间就是左孩子的最长后缀加上右孩子的最长前缀
        } else{
            return query(pos, rson);
        }
    }
}
    
int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        build(1, n, 1);
        stack<int> q;
        while(m --){
            char str[2];
            int x;
            scanf("%s", str);
            if(str[0] == 'D'){
                scanf("%d", &x);
                push_date(x, 0, 1, n, 1);
                q.push(x);
            } else if(str[0] == 'Q'){
                scanf("%d", &x);
                printf("%d\n", query(x, 1, n, 1));
            } else{
                if(q.size()){
                    push_date(q.top(), 1, 1, n, 1);
                    q.pop();
                }
            }
        }
    }
    return 0;
}
