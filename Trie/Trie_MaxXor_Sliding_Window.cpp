#include<cstdio>
#include<iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 101000 * 31, M = 101000;
int n, m, k;

int son[N][2], cnt[N], w[M], idx;


void insert(int x, int v){
    int p = 0;
    for(int i = 30; i >= 0; --i){
        int u = x >> i & 1;
        if(!son[p][u]){
            son[p][u] = ++idx;
        }
        p = son[p][u];
        cnt[p] += v;
    }
}

int query(int x){
    int ret = 0, p = 0;
    for(int i = 30; i >= 0; --i){
        int u = x >> i & 1;
        if(cnt[son[p][!u]]){
            p = son[p][!u];
            ret = ret * 2 + 1;
        }else{
            p = son[p][u];
            ret = ret * 2;
        }
    }
    return ret;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ){
        scanf("%d", &k);
        w[i] = w[i-1] ^ k;
    }
    
    insert(w[0], 1);//insert函数目的是插入时当前对应的01字典树所对应的二进制节点的数量++ 表示当前节点下面可选
    
    int ret = 0;
    for(int i = 1; i <= n; ++i){
        if(i > m){
            insert(w[i-m-1], -1);
        }
        ret = max(ret, query(w[i]));
        insert(w[i], 1);
    }
    printf("%d", ret);
}
