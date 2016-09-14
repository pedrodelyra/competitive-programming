#include <bits/stdc++.h>

#define MAX 512
#define INF (1 << 30)

using namespace std;

vector<int> graph[MAX];
int visited[MAX], parents[MAX], capacity[MAX][MAX];

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
			if(capacity[u][v] && not visited[v]) {
				parents[v] = u;
				visited[v] = true;
				q.push(v);
			}
		}

		q.pop();
	}

	return visited[destination];
}

int edmonds_karp(int n) {
	int max_flow = 0;
	while(bfs(1, n)) {
		int u = n, path_flow = INF;
		while(parents[u]) {
			path_flow = min(path_flow, capacity[parents[u]][u]);
			u = parents[u];
		}

		u = n;
		while(parents[u]) {
			capacity[parents[u]][u] -= path_flow;
			capacity[u][parents[u]] += path_flow;
			u = parents[u];
		}

		max_flow += path_flow;
	}

	return max_flow;
}

int main(void) {
	int n, m;
	while(scanf("%d %d", &n, &m), n | m) {
		memset(capacity, 0, sizeof capacity);

		graph[1].push_back(n + 1);
		capacity[1][n + 1] = INF;

		for(int i = 2; i < n; ++i) {
			int u, c;
			scanf("%d %d", &u, &c);
			graph[u].push_back(u + n);
			graph[u + n].push_back(u);
			capacity[u][u + n] = c;
		}

		for(int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			graph[u + n].push_back(v);
			graph[v].push_back(u + n);

			graph[v + n].push_back(u);
			graph[u].push_back(v + n);

			capacity[u + n][v] = capacity[v + n][u] = w;
		}

		printf("%d\n", edmonds_karp(n));

		for(int u = 1; u <= (n << 1); ++u)
			graph[u].clear();
	}

	return 0;
}
