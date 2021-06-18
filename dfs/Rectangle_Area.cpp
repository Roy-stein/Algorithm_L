#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<set>
#include<queue>
#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e5 + 10;

char a[15][15];
bool vis[15][15];
int n, m;
int T;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, int k, PII& minx, PII& maxx){
	minx = make_pair(min(x, minx.x), min(y, minx.y));
	maxx = make_pair(max(x, maxx.x), max(y, maxx.y));
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny] || a[nx][ny] != k)
			continue;
		vis[nx][ny] = 1;
		dfs(nx, ny, k, minx, maxx);
	}
}

int main(){
	cin >> T; 
	for(int pp = 1; pp <= T; ++ pp){
		memset(vis, 0, sizeof vis);
		cin >> n >> m;
		set<int> st;
		int cnt = 0, sum = 0;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				cin >> a[i][j];
				st.insert(a[i][j]);
			}
		}
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				if(!vis[i][j]){
					PII minx = make_pair(20, 20);
					PII maxx = make_pair(-1, -1);
					vis[i][j] = 1; 
					dfs(i, j, a[i][j], minx, maxx);
					++cnt;
					sum += (maxx.x - minx.x + 1) * (maxx.y - minx.y + 1);
//					cout << maxx.x << " " << maxx.y << endl;
				}
//		cout << cnt << " " << sum << endl;
		if(cnt == st.size() && sum == n * m)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
