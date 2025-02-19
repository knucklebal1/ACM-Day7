#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
const int N = 2e5+5, M = (5e5+5)*6;

int s, t;
int n, m, k;
bool st[N];//标记节点是否已被访问
int dis[N];
int head[N], edge[M], ne[M], w[M], idx;//head[N] 邻接表的头指针

void add(int a, int b, int c){
	edge[idx] = b;
	w[idx] = c;
	ne[idx] = head[a];
	head[a] = idx;
	idx ++ ;
}

void dijkstra(){
	memset(dis, 0x3f, sizeof dis);
	dis[s] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> q;
	q.push({dis[s], s});
	
	while (q.size())
	{
		auto t = q.top();
		q.pop();
		
		int ver = t.y;
		if (st[ver]) continue;
		st[ver] = true;
		
		for (int i = head[ver]; i != -1; i = ne[i])
		{
			int j = edge[i];
			if (dis[j] > dis[ver] + w[i])
			{
				dis[j] = dis[ver] + w[i];
				q.push({dis[j], j});
			}
		}
	}
}

int main(){
	cin >> n >> m >> k >> s >> t;
	memset(head, -1, sizeof head);
	for (int i = 0; i < m; i ++ )
	{
		int a, b, c;
		cin>>a>>b>>c;
		add(a, b, c), add(b, a, c);
		for (int j = 1; j <= k; ++j )
		{
			add(a + (j - 1) * n, b + j * n, 0);
			add(b + (j - 1) * n, a + j * n, 0);
			add(a + j * n, b + j * n, c);
			add(b + j * n, a + j * n, c);
		}
	}
	
	dijkstra();
	
	int ans = 0x3f3f3f3f;
	for (int i = 0; i <= k; i ++ ) ans = min(ans, dis[t + i * n]); 
	cout << ans;
	
	return 0;
}
