#include <bits/stdc++.h>

#define MAX 128

using namespace std;

vector<int> graph[MAX];
bool visited[MAX];

int dfs(int u) {
	int vis = 1;
	visited[u] = true;
	for(auto& v : graph[u]) {
		if(not visited[v]) {
			vis += dfs(v);
		}
	}
	return vis;
}

int main(void) {
	int n, m, root = 1, tc = 0;
	while(scanf("%d %d", &n, &m), n | m) {
		for(int i = 1; i <= m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		memset(visited, false, sizeof visited);
		printf("Teste %d\n%s\n\n", ++tc, dfs(root) == n ? "normal" : "falha");
		for(int u = 1; u <= n; ++u) graph[u].clear();
	}
	return 0;
}
