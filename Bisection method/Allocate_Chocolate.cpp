#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<set>

using namespace std;
typedef long long LL;
const int N = 1e5 + 10;

int a[N], c[N], v[N];
int n, m;

bool check(int bb){
	LL ret = 0;
	for(int i = 1; i <= n; ++i){
		ret += (c[i] / bb) * (v[i] / bb);
	}
//	printf("%d\n", ret);
	return ret >= m;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", c + i, v + i);
	check(3);
	int l = 1, r = 0x3f3f3f3f;
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(check(mid))
			l = mid;
		else
			r = mid - 1;
	}
	printf("%d", l);
}
