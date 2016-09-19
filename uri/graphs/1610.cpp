#include <bits/stdc++.h>

#define MAX 10005
#define UNVISITED 0
#define VISITED   1
#define EXPLORED  2

using namespace std;

vector<int> graph[MAX];
int cycles, visited[MAX];

void dfs(int u) {
	visited[u] = VISITED;
	for(auto& v : graph[u]) {
		if(visited[v] == UNVISITED) {
			dfs(v);
		} else if(visited[v] == VISITED) {
			++cycles;
			return;
		}
	}
	visited[u] = EXPLORED;
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
		}

		cycles = 0, memset(visited, UNVISITED, sizeof visited);
		for(int u = 1; u <= n && cycles == 0; ++u) {
			if(not visited[u]) dfs(u);
		}

		printf(cycles ? "SIM\n" : "NAO\n");

		for(int u = 1; u <= n; ++u) graph[u].clear();
	}

	return 0;
}
