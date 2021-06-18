#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;

const int N = 2 * 1e5 + 10;

int a[N];
int n, t;
LL aa, bb, ans1, ans2;

int main(){
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i ++ ){
        scanf("%d", a + i);
        if(a[i] < 0){
            LL tmp = aa;
            aa = bb;
            bb = tmp + 1;
        }
        else
            aa += 1;
        ans1 += aa; ans2 += bb;
    }
    printf("%lld %lld", ans2, ans1);
}
