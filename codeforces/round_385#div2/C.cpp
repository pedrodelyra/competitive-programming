#include <bits/stdc++.h>

#define MAX 1024

using namespace std;

vector<int> graph[MAX], visited(MAX);

int dfs(int u) {
	int k = 1;
	visited[u] = true;
	for(auto& v : graph[u]) {
		if(not visited[v]) {
			k += dfs(v);
		}
	}
	return k;
}

int main(void) {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<int> gov(k + 1);
	for(int i = 1; i <= k; ++i) {
		scanf("%d", &gov[i]);
	}
	for(int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int new_edges = 0, max_nodes = 0;
	for(auto& u : gov) {
		int nodes = dfs(u);
		new_edges += nodes * (nodes - 1) / 2;
		max_nodes = max(max_nodes, nodes);
	}
	int count = 0;
	for(int u = 1; u <= n; ++u) {
		if(not visited[u]) {
			++count;
		}
	}
	new_edges += count * max_nodes + (count * (count - 1)) / 2;
	printf("%d\n", new_edges - m);
	return 0;
}
