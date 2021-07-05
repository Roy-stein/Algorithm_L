#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 50;
int a[N], n;


// void quickSort(int l, int r){
//     if(l >= r)
//         return ;
//     int i = l-1, j = r+1, pivot = a[l+r >> 1];
//     while(i < j){
//         do ++i; while(a[i] < pivot);
//         do --j; while(a[j] > pivot);
//         if(i < j) swap(a[i], a[j]);
//         // cout << i << " " << j << endl;
//     }
//     // 用j不能取到右边界，把x取值改成向下取整
//     quickSort(l, j);
//     quickSort(j+1, r);
// }

// void quickSort(int l, int r){
//     if(l >= r)
//         return ;
//     int pivot = a[l];   //
//     int i = l, j = r;
//     while(i < j){
//         while(i < j && a[j] > pivot) --j;
//         if(i < j) a[i++] = a[j];
//         while(i < j && a[i] < pivot) ++i;
//         if(i < j) a[j--] = a[i];
//     }
//     a[i] = pivot;
//     quickSort(l, i-1);
//     quickSort(i+1, r);
// }

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    quickSort(0, n-1);
    for(int i = 0; i < n; ++i)
        cout << a[i] << " ";
}
