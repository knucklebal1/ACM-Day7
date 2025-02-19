#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 110;
const int MAXQ = 110;

int dp[MAXN][MAXQ];
vector<pair<int, int>> children[MAXN];

void dfs(int u, int parent, int Q) {
	for (auto &child : children[u]) {
		int v = child.first;
		int w = child.second;
		if (v == parent) continue;
		dfs(v, u, Q);
		for (int k = Q; k >= 0; --k) {
			for (int l = 0; l < k; ++l) {
				dp[u][k] = max(dp[u][k], dp[u][k - l - 1] + dp[v][l] + w);
			}
		}
	}
}

int main() {
	int N, Q;
	cin >> N >> Q;
	for (int i = 1; i < N; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		children[u].emplace_back(v, w);
		children[v].emplace_back(u, w);
	}
	dfs(1, -1, Q);
	cout << dp[1][Q];
	return 0;
}
