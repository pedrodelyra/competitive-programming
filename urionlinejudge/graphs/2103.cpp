#include <bits/stdc++.h>

#define MAX 10005

using namespace std;
using ii  = pair<int, int>;
using iii = tuple<int, int, int>;

vector<int> tree[MAX];
int visited[MAX], subtree[MAX], parents[MAX];

int dfs(int u) {
	visited[u] = true;
	for(auto& v : tree[u]) {
		if(not visited[v]) {
			parents[v] = u;
			subtree[u] += dfs(v);
		}
	}
	return subtree[u] += 1;
}

int main(void) {
	int tc, root = 1, mod = 1300031;
	scanf("%d", &tc);
	while(tc--) {
		int n, ans = 0;
		scanf("%d", &n);
		vector<iii> edges;
		for(int i = 1; i < n; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			tree[u].push_back(v);
			tree[v].push_back(u);
			edges.push_back(iii(u, v, w));
		}
		memset(parents, 0, sizeof parents);
		memset(subtree, 0, sizeof subtree);
		memset(visited, 0, sizeof visited);
		dfs(root);
		for(auto& edge : edges) {
			int u, v, w;
			tie(u, v, w) = edge;
			int a = (u == parents[v]) ? n - subtree[v] : n - subtree[u], b = (u == parents[v]) ? subtree[v] : subtree[u];
			ans = (ans + (w * ((a * b) % mod) % mod)) % mod;
		}
		printf("%d\n", ans);

		for(int u = 1; u <= n; ++u) {
			tree[u].clear();
		}
	}
	return 0;
}
