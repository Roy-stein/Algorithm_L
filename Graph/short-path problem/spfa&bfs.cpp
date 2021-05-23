#include<bits/stdc++.h>
#define ll long long
#define PII pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 305, M = N*N;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
PII st, ed;
bool vis[N][N];
int dis[N][N], h[M], ne[M],e[M], idx;
int n, m, k;
char g[N][N];

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int main(){
    memset(dis, 0x3f, sizeof(dis));
    memset(h, -1, sizeof(h));
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; ++i){
        getchar();
        for(int j = 0; j < m; ++j){
            scanf("%c", &g[i][j]);
            if(g[i][j] == 'S')
                st = {i, j};
            else if(g[i][j] == 'T')
                ed = {i, j};
        }
    }
    for(int i = 1; i <= k; ++i){
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        add(a*m+b, c*m+d);
        add(c*m+d, a*m+b);
    }
    
    queue<PII> q;
    q.push({st.fi, st.se});
    dis[st.fi][st.se] = 0;
    
    while(q.size()){
        PII p = q.front(); q.pop();
        int x = p.fi, y = p.se;
        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] == '#')
                continue;
            if(dis[nx][ny] > dis[x][y] + 1){
                dis[nx][ny] = dis[x][y]+1;
                q.push({nx, ny});
            }
            for(int j = h[x*m+y]; j != -1; j = ne[j]){
                int t = e[j];
                int tx = t / m, ty = t % m;
                if(g[tx][ty] != '#' && dis[tx][ty] > dis[x][y] + 3){
                    dis[tx][ty] = dis[x][y]+3;
                    q.push({tx, ty});
                }
            }
        }
    }
    if(dis[ed.fi][ed.se] == 0x3f3f3f3f)
            dis[ed.fi][ed.se] = -1;
        printf("%d", dis[ed.fi][ed.se]);
}
