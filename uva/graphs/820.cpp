#include <bits/stdc++.h>

#define MAX 128
#define INF 0x3f3f3f3f

using namespace std;

int graph[MAX][MAX], parents[MAX];
bool visited[MAX];

bool bfs(int n, int source, int destination) {
	queue<int> q;
	memset(visited, false, sizeof visited);
	memset(parents, 0, sizeof parents);
	parents[source] = 0;
	visited[source] = true;
	q.push(source);
	while(not q.empty()) {
		int u = q.front();

		if(u == destination) break;

		for(int v = 1; v <= n; ++v) {
			if(graph[u][v] && visited[v] == false) {
				parents[v] = u;
				visited[v] = true;
				q.push(v);
			}
		}

		q.pop();
	}

	return visited[destination];
}

int edmonds_karp(int n, int source, int destination) {
	int max_flow = 0;
	while(bfs(n, source, destination)) {
		int u, min_edge;
		u = destination, min_edge = INF;
		while(parents[u]) {
			min_edge = min(min_edge, graph[parents[u]][u]);
			u = parents[u];
		}

		u = destination;
		while(parents[u]) {
			graph[parents[u]][u] -= min_edge;
			graph[u][parents[u]] += min_edge;
			u = parents[u];
		}

		max_flow += min_edge;
	}

	return max_flow;
}

int main(void) {
	int n, tc = 0;
	while(scanf("%d", &n), n) {
		int source, destination, m;
		scanf("%d %d %d", &source, &destination, &m);
		memset(graph, 0, sizeof graph);
		for(int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			graph[u][v] += w;
			graph[v][u] += w;
		}

		printf("Network %d\nThe bandwidth is %d.\n\n", ++tc, edmonds_karp(n, source, destination));
	}

	return 0;
}
