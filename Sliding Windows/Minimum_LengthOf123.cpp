#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 200050;
int n;
char s[N];

int Solve(){
    scanf("%s", s);
    int a[4] = {0};
    int l = 0, r = 0;
    int ret = N * 2;
    while(s[r] != '\0'){
        ++a[s[r] - '0'];
        while(a[1] && a[2] && a[3]){
            ret = min(ret, r - l + 1);
            --a[s[l++] - '0'];
        }
        ++r;
    }
    if(ret != N * 2)
        return ret;
    return 0;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        printf("%d\n", Solve());
}
