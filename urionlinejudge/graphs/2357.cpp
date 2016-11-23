#include <bits/stdc++.h>

#define MAX 10005

using namespace std;

vector<int> graph[MAX];
int visiteds, edges, visited[MAX];

void dfs(int u) {
	visited[u] = true;
	for(auto& v : graph[u]) {
		if(not visited[v]) {
			dfs(v);
		}
		++edges;
	}
	++visiteds;
}

int main(void) {
	int n, m;
	while(~scanf("%d %d", &n, &m)) {
		bool ans = true;
		for(int i = 1; i <= m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		memset(visited, false, sizeof visited);
		for(int u = 1; ans and u <= n; ++u) {
			if(not visited[u]) {
				visiteds = edges = 0;
				dfs(u);
				ans = edges == (visiteds - 1) << 1;
			}
		}
		printf(ans ? "Seguro\n" : "Inseguro\n");

		for(int u = 1; u <= n; ++u) {
			graph[u].clear();
		}
	}
	return 0;
}
