#include <iostream>

using namespace std;

const int N = 1005;
int a[N],k,p,n,x,y,sum,cnt;
//cnt存初始数组大于等于y的个数

int main()
{
    cin>>n>>k>>p>>x>>y;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
        sum+=a[i];
        if(a[i]>=y) cnt++;
    }
    if(cnt+n-k<=n/2){   //这里得特判  初始数组可能一半以上的数都小于y
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
