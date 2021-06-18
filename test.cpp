#include<iostream>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N = 1e5 + 10;
LL tree[N * 4], A[N * 4], mark[N * 4], n, m;		//经验表明：开4倍空间不会越界 

void push_down(LL p, LL len){
	mark[p * 2] += mark[p];
	mark[p * 2 + 1] += mark[p];	//更新懒标记数组 
	tree[p * 2] += mark[p] * (len - len/2);
	tree[p * 2 + 1] += mark[p] * (len / 2);	//更新树的值， 右边的区间可能要短一点 
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

void update(LL l, LL r, LL d, LL p, LL cl, LL cr){		//cl, cr代表当前结点对应的区间 
	if(l > cr || r < cl){	//区间无交集 
		return ;
	}else if(cl >= l && cr <= r){	//当前节点对应的区间包含在目标区间中 
		tree[p] += d * (cr - cl + 1);
		if(cr > cl)					//如果不是叶子结点， 加上懒标记 
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
