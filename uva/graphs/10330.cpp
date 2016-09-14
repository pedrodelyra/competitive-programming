#include <bits/stdc++.h>

#define MAX 512
#define INF (1 << 30)

using namespace std;

vector<int> graph[MAX];
int VISITED, visited[MAX], parents[MAX], cap[MAX][MAX];

bool bfs(int source, int destination) {
	queue<int> q;
	visited[source] = ++VISITED;
	q.push(source);
	while(not q.empty()) {
		int u = q.front();
		for(auto& v : graph[u]) {
			if(visited[v] != VISITED && cap[u][v]) {
				visited[v] = VISITED;
				parents[v] = u;
				q.push(v);
			}
		}
		q.pop();
	}

	return visited[destination] == VISITED;
}

int edmonds_karp(int source, int destination) {
	int max_flow = 0;
	while(bfs(source, destination)) {
		int u = destination, path_flow = INF;
		while(u) {
			path_flow = min(path_flow, cap[parents[u]][u]);
			u = parents[u];
		}

		u = destination;
		while(u) {
			cap[parents[u]][u] -= path_flow;
			cap[u][parents[u]] += path_flow;
			u = parents[u];
		}

		max_flow += path_flow;	
	}

	return max_flow;
}

int main(void) {
	int n, m;
	while(scanf("%d", &n) != EOF) {
		memset(cap, 0, sizeof cap);
		for(int u = 1; u <= n; ++u) {
			scanf("%d", &cap[u][u + n]);
			graph[u].push_back(u + n);
			graph[u + n].push_back(u);
		}

		scanf("%d", &m);
		for(int i = 1; i <= m; ++i) {
			int u, v, c;
			scanf("%d %d %d", &u, &v, &c);
			graph[u + n].push_back(v);
			graph[v].push_back(u + n);
			cap[u + n][v] = c;
		}

		int in, out;
		scanf("%d %d", &in, &out);
		for(int i = 1; i <= in; ++i) {
			int u;
			scanf("%d", &u);
			graph[0].push_back(u);
			cap[0][u] = INF;
		}

		for(int i = 1; i <= out; ++i) {
			int u;
			scanf("%d", &u);
			graph[u + n].push_back(2 * n + 1);
			cap[u + n][2 * n + 1] = INF;
		}

		int ans = edmonds_karp(0, 2 * n + 1);
		printf("%d\n", ans);

		for(int i = 0; i <= 2 * n + 1; ++i) graph[i].clear();
	}

	return 0;
}
