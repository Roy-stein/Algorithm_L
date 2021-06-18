// Êı×éÑÓÉì 

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 1e5 + 50;
int a[N], b[N];
int T, x, n;

int main(){
    int T;
    cin >> T;
    for(; T; --T){
        cin >> n >> x;
        LL ret = 0;
        for(int i = 1; i <= n; ++i)
            cin >> a[i], b[i] = a[i], ret += a[i];
        while(x){
            for (int i = 1; i <= n; i ++ ){
                if(a[i] % x == 0){
                    ret += b[i];
                    a[i] /= x;
                }else{
                    x = 0;
                    break;
                }
            }
        }
        cout << ret << endl;
    }
}

