#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
const int N = 1000005;

struct E {
	int v, w, next;
}e[N], re[N];
struct Node {
	int v, d;
	Node(int v, int d):v(v), d(d){}
	bool operator < (const Node &w)const {
		return d > w.d;
	}
};
int t, n, m, len, rlen, head[N], rhead[N], d[N];
bool vis[N];
void add(int u, int v, int w) {
	e[len].v = v;
	e[len].next = head[u];
	e[len].w = w;
	head[u] = len++;
}
void radd(int u, int v, int w) {
	re[rlen].v = v;
	re[rlen].next = rhead[u];
	re[rlen].w = w;
	rhead[u] = rlen++;
}
void dijkstra(int u) {
	memset(d, 0x3f, sizeof(d));
	memset(vis, false, sizeof(vis));
	d[u] = 0;
	priority_queue<Node> q; 
	q.push(Node(u, 0));
	while (!q.empty()) {
		u = q.top().v;
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (int j = head[u]; j; j = e[j].next) { 
			int v = e[j].v;
			int w = e[j].w;
			if (!vis[v] && d[v] > d[u] + w) {
				d[v] = d[u] +w;
				q.push(Node(v, d[v]));
			}
		}
	}
}

int main() {
	cin>>t;
	while (t--) {
		cin>>n>>m;
		len = 1, rlen = 1;
		memset(head, 0, sizeof(head));
		memset(rhead, 0, sizeof(head));
		int u, v, w;
		for (int i = 1; i <= m; i++) {
			cin>>u>>v>>w;
			add(u, v, w);
			radd(v, u, w);
		}
		dijkstra(1);
		int ans = 0;
		for (int i = 1; i <= n; i++) ans += d[i];
		memcpy(head, rhead, sizeof(rhead));
		memcpy(e, re, sizeof(re));
		dijkstra(1);		
		for (int i = 1; i <= n; i++) ans += d[i];
		cout<<ans;
	} 
	return 0;
}

