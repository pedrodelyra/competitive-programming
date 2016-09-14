#include <bits/stdc++.h>

#define MAX 2048

using namespace std;

vector<int> graph[MAX], reversed_graph[MAX];
bool visited[MAX];

void dfs(int u, stack<int>& s) {
	visited[u] = true;

	for(auto& v : graph[u]) {
		if(not visited[v])
			dfs(v, s);
	}

	s.push(u);
}

void dfs(int u) {
	visited[u] = true;

	for(auto& v : reversed_graph[u]) {
		if(not visited[v])
			dfs(v);
	}
}

int main(void) {
	int n, m;
	while(scanf("%d %d", &n, &m), (n | m)) {
		for(int i = 0; i < m; ++i) {
			int u, v, t;
			scanf("%d %d %d", &u, &v, &t);

			graph[u].push_back(v);
			reversed_graph[v].push_back(u);

			if(t == 2) {
				graph[v].push_back(u);
				reversed_graph[u].push_back(v);
			}
		}

		stack<int> s;
		memset(visited, false, sizeof visited);
		for(int u = 1; u <= n; ++u) {
			if(not visited[u]) {
				dfs(u, s);
			}
		}

		int scc = 0;
		memset(visited, false, sizeof visited);
		while(not s.empty()) {
			int u = s.top();
			s.pop();

			if(not visited[u]) {
				dfs(u);
				++scc;
			}
		}

		printf("%d\n", scc == 1);

		for(int u = 1; u <= n; ++u) {
			graph[u].clear();
			reversed_graph[u].clear();
		}
	}

	return 0;
}
