#include <bits/stdc++.h>

#define MAX 100005

using namespace std;

vector<int> graph[MAX], reversed_graph[MAX], dag[MAX];
int components[MAX], in_degree[MAX];
bool visited[MAX];

void dfs(int u, int color) {
	visited[u] = true;

	for(auto& v : reversed_graph[u]) {
		if(not visited[v])
			dfs(v, color);
	}

	components[u] = color;
}

void dfs(int u, stack<int>& s) {
	visited[u] = true;

	for(auto& v : graph[u]) {
		if(not visited[v])
			dfs(v, s);
	}

	s.push(u);
}

int main(void) {
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		int n, m, scc = 0;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
			reversed_graph[v].push_back(u);
		}

		stack<int> s;
		memset(visited, false, sizeof visited);
		memset(components, 0, sizeof components);
		for(int u = 1; u <= n; ++u) {
			if(not visited[u]) {
				dfs(u, s);
			}
		}

		memset(visited, false, sizeof visited);
		while(not s.empty()) {
			int u = s.top();
			s.pop();

			if(not visited[u]) {
				dfs(u, ++scc);
			}
		}

		memset(in_degree, 0, sizeof in_degree);
		for(int u = 1; u <= n; ++u) {
			for(auto& v : graph[u]) {
				if(components[u] != components[v]) {
					dag[components[u]].push_back(components[v]);
					in_degree[components[v]]++;
				}
			}
		}

		int count = 0;
		for(int u = 1; u <= scc; ++u) {
			if(in_degree[u] == 0) {
				++count;
			}
		}

		printf("%d\n", count);

		for(int u = 1; u <= scc; ++u) {
			dag[u].clear();
		}

		for(int u = 1; u <= n; ++u) {
			graph[u].clear();
			reversed_graph[u].clear();
		}

	}

	return 0;
}
