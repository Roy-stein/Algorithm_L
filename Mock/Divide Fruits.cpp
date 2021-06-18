#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int t, a[10];

int main(){
    cin >> t;
    for(; t; --t){
        for(int i = 1; i <= 3; ++i)
            cin >> a[i];
        sort(a+1, a+1+3);
        int ret = 0;
        if(a[3]) ++ ret, -- a[3];
        if(a[1]) ++ ret, -- a[1];
        if(a[2]) ++ ret, -- a[2];
        if(a[3] && a[1]) ++ ret, --a[1], --a[3];
        if(a[3] && a[2]) ++ ret, --a[2], --a[3];
        if(a[2] && a[1]) ++ ret, --a[1], --a[2];
        if(a[1] && a[2] && a[3]) ++ ret;
        cout << ret << endl;
    }
}
