#include <iostream>

using namespace std;

const int N = 1005;
int a[N],k,p,n,x,y,sum,cnt;
//cnt���ʼ������ڵ���y�ĸ���

int main()
{
    cin>>n>>k>>p>>x>>y;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
        sum+=a[i];
        if(a[i]>=y) cnt++;
    }
    if(cnt+n-k<=n/2){   //���������  ��ʼ�������һ�����ϵ�����С��y
        puts("-1");    
        return 0;
    }
    int j=k+1;
    while(cnt<=n/2) a[++k]=y,sum+=y,cnt++;
    while(k<n) a[++k]=1,sum++;
    if(sum>x) puts("-1");
    else{
        for(int i=j;i<=n;i++) cout<<a[i]<<' ';
    }
    return 0;
}
