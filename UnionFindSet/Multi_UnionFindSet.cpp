#include<cstdio>
using namespace std;

const int N = 50000;
int f[N*4 + 10];
int n, k;

int find(int i){
    return f[i] == i ? i : f[i] = find(f[i]);
}

void merge(int x, int y){
    if(find(x) != find(y)){
        f[find(x)] = find(y);
    }
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= 4 * n; ++i)
        f[i] = i;
    int ret = 0;
    for(int i = 1; i <= k; ++i){
        int d, x, y;
        scanf("%d%d%d0", &d, &x, &y);
        if(x<1||y<1||x>n||y>n)
        {
            ret++;
            continue;
        }
        if(d == 1){
            if(find(x) == find(y+n) || find(x) == find(y+2*n) || find(x) == find(y+3*n)){
                ++ret;
            }else{
                merge(find(x), find(y));
                merge(find(x+n), find(y+n));
                merge(find(x+2*n), find(y+2*n));
                merge(find(x+3*n), find(y+3*n));
            }
        }else if(d == 2){
            if(find(x) == find(y) || find(x) == find(y+2*n) || find(x) == find(y+3*n)){
                ++ret;
            }else{
                merge(find(x), find(y+n));
                merge(find(x+n), find(y+2*n));
                merge(find(x+2*n), find(y+3*n));
                merge(find(x+3*n), find(y));
            }
        }else{
            if(find(x) == find(y) || find(x) == find(y+n) || find(x) == find(y+3*n)){
                ++ret;
            }else{
                merge(find(x), find(y+2*n));
                merge(find(x+n), find(y+3*n));
                merge(find(x+2*n), find(y));
                merge(find(x+3*n), find(y+n));
            }
        }
    }
    printf("%d", ret);
}
