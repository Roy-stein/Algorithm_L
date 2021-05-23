#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 1e5 + 5;
int e[N], w[N], dis[N], ne[N], head[N], idx;
bool vis[N];
int m, n;

void add(int a, int b, int c){
	e[idx] = b;
	w[idx] = c;
	ne[idx] = head[a];
	head[a] = idx++;		//存放边的信息 
}

int spfa(){
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	queue<int> q;
	q.push(1);
	
	vis[1] = true;
	while(q.size()){
		int t = q.front(); q.pop();
		vis[t] = 0;
		
		for(int i = head[t]; i != -1; i = ne[i]){
			int j = e[i];
			if(dis[j] > dis[t] + w[i]){			//以t为起始边
				dis[j] = dis[t] + w[i];
				if(!vis[j]){
					q.push(j);
					vis[j] = 1;
				}
			}
		}
	}
	if(dis[n] == 0x3f3f3f3f)
		return -1;
	return dis[n];
}

int main(){
	cin >> n >> m;
	memset(head, -1, sizeof(head));
	for(int i = 1; i <= m; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	int ret = spfa();
	if(ret == -1)
		cout << "impossible";
	else
		cout << ret;
}
