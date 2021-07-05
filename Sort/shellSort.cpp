#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 50;
int a[N], n;

void shellSort(){
    int gap, i, j;
    int tmp;
    for(gap = n >> 1; gap > 0; gap >>= 1){			//确定间隔 
        for(i = gap; i < n; ++i){
            tmp = a[i];
            for(j = i-gap; j >= 0 && a[j] > tmp; j-= gap)		//逐次进行插入排序 
                a[j+gap] = a[j];
            a[j+gap] = tmp;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    shellSort();
    for(int i = 0; i < n; ++i)
        cout << a[i] << " ";
}
