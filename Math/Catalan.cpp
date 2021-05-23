#include<iostream>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
int a[105];

void Catalan(){
	a[0] = a[1] = 1;
	for(int i = 2; i <= 100; ++i){
		a[i] = 0;
		for(int j = 0; j < i; ++j){
			a[i] = (a[i] + (ll)a[j] * a[i-1-j] % mod) % mod;
		}
	}
}

int main(){
	Catalan();
	for(int i = 1; i < 80; ++i)
		cout << a[i] << " ";
}
