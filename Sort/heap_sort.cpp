#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 50;
int a[N], n;

void max_heapify(int start, int end){
    int dad = start;
    int son = dad*2 + 1;
    while(son <= end){
        if(son + 1 <= end && a[son+1] > a[son])
            ++son;
        if(a[dad] > a[son]) //如果父节点大于子节点代表调整完毕，直接跳出函数
            return ;
        else{
            swap(a[dad], a[son]);
            dad = son;
            son = dad*2 + 1;
        }
    }
}

void heap_sort(){
    //初始化， i从最后一个父节点开始调整
    for(int i = n/2 - 1; i >= 0; --i)
        max_heapify(i, n-1);
    //先将第一个元素和已排好元素前一位元素做交换，再重新调整，知道排序完毕
    for(int i = n-1; i > 0; --i){
        swap(a[0], a[i]);
        max_heapify(0, i-1);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    heap_sort();
    for(int i = 0; i < n; ++i)
        cout << a[i] << " ";
}
