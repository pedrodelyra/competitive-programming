#include <bits/stdc++.h>

#define MAX 100005
#define UNVISITED 0
#define VISITED   1
#define EXPLORED  2

using namespace std;

vector<int> graph[MAX];
int cycles, visited[MAX], parents[MAX];

int dfs(int u) {
	visited[u] = VISITED;
	for(auto& v : graph[u]) {
		if(visited[v] == UNVISITED) {
			parents[v] = u;
			dfs(v);
		} else if(parents[u] != v && visited[v] == VISITED) {
			cycles++;
		}
	}
	visited[u] = EXPLORED;
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int ans = 0;
	for(int u = 1; u <= n; ++u) {
		if(not visited[u]) {
			cycles = 0;
			dfs(u);
			if(cycles == 0) ++ans;
		}
	}
	printf("%d\n", ans);

	return 0;
}
