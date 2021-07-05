#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 50;
int a[N], tmp[N], n;

void merge_sort(int l, int r){
    if(l >= r)
        return ;
    
    int mid = l + (r-l) / 2;
    merge_sort(l, mid);
    merge_sort(mid+1, r);
    
    int k = l, i = l, j = mid+1;
    while(i <= mid && j <= r){
        if(a[i] < a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while(i <= mid) tmp[k++] = a[i++];
    while(j <= r) tmp[k++] = a[j++];
    for(int i = l; i <= r; ++i)
        a[i] = tmp[i];
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    merge_sort(0, n-1);
    for(int i = 0; i < n; ++i)
        cout << a[i] << " ";
}
