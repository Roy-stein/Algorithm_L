#include<iostream>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N = 1e5 + 10;
LL tree[N * 4], A[N * 4], mark[N * 4], n, m;		//�����������4���ռ䲻��Խ�� 

void push_down(LL p, LL len){
	mark[p * 2] += mark[p];
	mark[p * 2 + 1] += mark[p];	//������������� 
	tree[p * 2] += mark[p] * (len - len/2);
	tree[p * 2 + 1] += mark[p] * (len / 2);	//��������ֵ�� �ұߵ��������Ҫ��һ�� 
	mark[p] = 0;
}

void build(LL p, LL l, LL r){
	if(l == r){
		tree[p] = A[l];
	}else{
		LL mid = l + (r-l) / 2;
		build(p*2, l, mid);
		build(p*2+1, mid+1, r);
		tree[p] = tree[p*2] + tree[p*2+1];
	}
}

void update(LL l, LL r, LL d, LL p, LL cl, LL cr){		//cl, cr����ǰ����Ӧ������ 
	if(l > cr || r < cl){	//�����޽��� 
		return ;
	}else if(cl >= l && cr <= r){	//��ǰ�ڵ��Ӧ�����������Ŀ�������� 
		tree[p] += d * (cr - cl + 1);
		if(cr > cl)					//�������Ҷ�ӽ�㣬 ��������� 
			mark[p] += d;
	}else{
		LL mid = l + (r-l) / 2;
		push_down(p, cr - cl + 1);
		update(l, r, d, p*2, cl, mid);
		update(l, r, d, p*2+1, mid+1, cr);
	}
}

int main(){
	for(int i = 1; i <= 5; ++i)
		A[i] = i;
}
