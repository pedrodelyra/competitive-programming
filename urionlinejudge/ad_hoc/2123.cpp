#include <bits/stdc++.h>

#define MAX 256
#define INF 0x2f2f2f2f

using namespace std;

vector<int> graph[MAX];
int visited[MAX], parents[MAX], horse_cap[MAX], cap[MAX][MAX];

bool bfs(int source, int destination) {
	queue<int> q;
	memset(visited, false, sizeof visited);
	parents[source] = -1;
	visited[source] = true;
	q.push(source);
	while(not q.empty()) {
		auto u = q.front();
		for(auto& v : graph[u]) {
			if(cap[u][v] && not visited[v]) {
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
		int u = destination, path_flow = INF;
		while(~parents[u]) {
			path_flow = min(path_flow, cap[parents[u]][u]);
			u = parents[u];
		}

		u = destination;
		while(~parents[u]) {
			cap[parents[u]][u] -= path_flow;
			cap[u][parents[u]] += path_flow;
			u = parents[u];
		}

		max_flow += path_flow;
	}

	return max_flow;
}

int main(void) {
	int n, m, k, tc = 0;
	while(~scanf("%d %d %d", &n, &m, &k)) {
		const int source = 0, destination = n + m + 1;
		for(int u = 1; u <= n; ++u) {
			scanf("%d", &horse_cap[u]);
		}

		memset(cap, 0, sizeof cap);
		for(int soldier = 1; soldier <= m; ++soldier) {
			graph[source].push_back(soldier);
			graph[soldier].push_back(source);
			cap[source][soldier] = 1;
		}

		for(int i = 1; i <= k; ++i) {
			int horse, soldier;
			scanf("%d %d", &horse, &soldier);
			graph[soldier].push_back(m + horse);
			graph[m + horse].push_back(soldier);
			cap[soldier][m + horse] = 1;
		}

		for(int u = 1; u <= n; ++u) {
			int horse = m + u;
			graph[horse].push_back(destination);
			graph[destination].push_back(horse);
			cap[horse][destination] = horse_cap[u];
		}

		printf("Instancia %d\n%d\n\n", ++tc, edmonds_karp(source, destination));

		for(int u = source; u <= destination; ++u) graph[u].clear();
	}

	return 0;
}
