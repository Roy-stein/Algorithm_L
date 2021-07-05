// acwing : 3729. 改变数组元素

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2 * 1e5 + 50;
int a[N], n, T;

int main(){
    cin >> T;
    while(T --){
        cin >> n;
        for (int i = 1; i <= n; i ++ )
            cin >> a[i];
        int l = n+1;
        for(int i = n; i >= 1; --i){
            l = min(l, i - a[i] + 1);
            if(i >= l)
                a[i] = 1;
        }
        for(int i = 1; i <= n; ++i)
            cout << a[i] << " ";
        cout << endl;
    }
}
