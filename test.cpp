#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int mod = 10007;
const int N = 2 * 1e5 + 50;
int n;
LL a[N];

void Catalan(){
	a[0] = a[1] = 1;
	for(int i = 2; i < N; ++i){
			a[i] = a[i-1] * (4 * i - 2) / (i + 1) % mod;
	}
}

int main(){
    scanf("%d", &n);
    Catalan();
     for(int i = 1; i <= 2 * n; ++i)
         printf("%lld ", a[i]);
//    printf("%lld", a[n]);
}
