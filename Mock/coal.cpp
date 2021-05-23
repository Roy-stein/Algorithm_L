#include<bits/stdc++.h>
#define ll long long
using namespace std;

long long N = 2021041820210418;
long long num[5000], pos;

int main(){
	for(long long i = 1; i*i <= N; ++i)
		if(N%i == 0){
			num[pos++] = i;
			if(N/i != i)
				num[pos++] = N/i;
		}
	cout << pos << endl;
	ll ret = 0;
	for(ll a = 0; a < pos; ++a)
		for(ll b = 0; b < pos; ++b)
			for(ll c = 0; c < pos; ++c)
				if(num[a]*num[b]*num[c] == N)
					++ret;
	cout << ret;
}
