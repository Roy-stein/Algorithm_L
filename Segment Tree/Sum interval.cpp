#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

LL tree[N * 4], A[N * 4], mark[N * 4], n, m, d, l, r;		//�����������4���ռ䲻��Խ�� 
char c;

void push_down(LL p, LL len){
	mark[p * 2] += mark[p];
	mark[p * 2 + 1] += mark[p];	//������������� 
	tree[p * 2] += mark[p] * (len - len/2);
	tree[p * 2 + 1] += mark[p] * (len / 2);	//��������ֵ�� �ұߵ��������Ҫ��һ�� 
	mark[p] = 0;				//������� 
}

void build(LL p = 1, LL l = 1, LL r = n){
	if(l == r){
		tree[p] = A[l];
	}else{
		LL mid = l + (r-l) / 2;
		build(p*2, l, mid);
		build(p*2+1, mid+1, r);
		tree[p] = tree[p*2] + tree[p*2+1];
	}
}

void update(LL l, LL r, LL d, LL p = 1, LL cl = 1, LL cr = n){		//cl, cr����ǰ����Ӧ������ 
	if(cl > r || cr < l){	//�����޽��� 
		return ;
	}else if(cl >= l && cr <= r){	//��ǰ�ڵ��Ӧ�����������Ŀ��������
		tree[p] += d * (cr - cl + 1);
		if(cr > cl)					//�������Ҷ�ӽ�㣬 ��������� 
			mark[p] += d;
	}else{
		LL mid = cl + (cr-cl) / 2;
		push_down(p, cr - cl + 1);
		update(l, r, d, p*2, cl, mid);
		update(l, r, d, p*2+1, mid+1, cr);
		tree[p] = tree[p*2] + tree[p*2+1];
	}
}

LL query(LL l, LL r, LL p = 1, LL cl = 1, LL cr = n){
	if(cl > r || cr < l){
		return 0;
	}else if(cl >= l && cr <= r){
		return tree[p];
	}else{
		LL mid = cl + (cr-cl) / 2;
		push_down(p, cr - cl + 1);
		return query(l, r, p*2, cl, mid) + query(l, r, p*2+1, mid+1, cr);
	}
} 

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> A[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i ++ ){
        cin >> c;
        if(c == 'Q'){
            cin >> l >> r;
            cout << query(l, r, 1, 1, n) << endl;
        }else if(c == 'C'){
            cin >> l >> r >> d;
            update(l, r, d, 1, 1, n);
        }
    }
}
