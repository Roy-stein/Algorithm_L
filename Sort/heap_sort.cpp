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
        if(a[dad] > a[son]) //������ڵ�����ӽڵ���������ϣ�ֱ����������
            return ;
        else{
            swap(a[dad], a[son]);
            dad = son;
            son = dad*2 + 1;
        }
    }
}

void heap_sort(){
    //��ʼ���� i�����һ�����ڵ㿪ʼ����
    for(int i = n/2 - 1; i >= 0; --i)
        max_heapify(i, n-1);
    //�Ƚ���һ��Ԫ�غ����ź�Ԫ��ǰһλԪ���������������µ�����֪���������
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
