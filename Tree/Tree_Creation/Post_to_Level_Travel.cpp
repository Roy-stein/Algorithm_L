#include<string>
#include<iostream>
#include <cstring>
#include<algorithm>
#include <set>
#include<map>
#include<vector>
using namespace std;
#define ll long long
#define M 100000

int a[100], n, m;
int tree[100];

void build(int now){
	if(now > m)
		return ;
	tree[now] = a[n--];
	build(now*2+1);
	build(now*2);
}

int main(){
	cin >> n;
	m = n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	build(1);
	for(int i = 1; i <= m; ++i){
		if(i != 1)
			cout << " " << tree[i];
		else
			cout << tree[i];
	}
}
