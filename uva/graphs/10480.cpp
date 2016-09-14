#include <bits/stdc++.h>

#define MAX 64
#define INF (1 << 30)

using namespace std;

vector<int> graph[MAX];
int visited[MAX], parents[MAX], components[MAX], capacity[MAX][MAX];

bool bfs(int source, int destination) {
	queue<int> q;
	memset(visited, false, sizeof visited);
	parents[source] = 0;
	visited[source] = true;
	q.push(source);
	while(not q.empty()) {
		int u = q.front();

		if(u == destination) break;

		for(auto& v : graph[u]) {
			if(capacity[u][v] > 0 && visited[v] == false) {
				parents[v] = u;
				visited[v] = true;
				q.push(v);
			}
		}

		q.pop();
	}

	return visited[destination];
}

int edmonds_karp(int source, int destination) {
	int max_flow = 0;
	while(bfs(source, destination)) {
		int u, path_flow;
		u = destination, path_flow = INF;
		while(parents[u]) {
			path_flow = min(path_flow, capacity[parents[u]][u]);
			u = parents[u];
		}

		u = destination;
		while(parents[u]) {
			capacity[parents[u]][u] -= path_flow;
			capacity[u][parents[u]] += path_flow;
			u = parents[u];
		}

		max_flow += path_flow;
	}

	return max_flow;
}

void dfs(int u, int color) {
	visited[u] = true;

	for(int &v : graph[u]) {
		if(capacity[u][v] > 0 && visited[v] == false) {
			dfs(v, color);
		}
	}

	components[u] = color;
}

int main(void) {
	int n, m;
	while(scanf("%d %d", &n, &m), (n | m)) {
		memset(capacity, 0, sizeof capacity);
		for(int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);

			graph[u].push_back(v);
			graph[v].push_back(u);
			capacity[u][v] += w;
			capacity[v][u] += w;
		}

		edmonds_karp(1, 2);
		memset(components, 0, sizeof components);
		memset(visited, false, sizeof visited);
		dfs(1, 1);
		for(int u = 1; u <= n; ++u) {
			if(components[u]) {
				for(auto& v : graph[u]) {
					if(components[u] != components[v]) {
						printf("%d %d\n", u, v);
					}
				}
			}
		}
		printf("\n");

		for(int u = 1; u <= n; ++u)
			graph[u].clear();
	}

	return 0;
}
