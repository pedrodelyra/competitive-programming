#include <bits/stdc++.h>

#define MAX 128
#define oo  0x2f2f2f2f

using namespace std;

vector<int> graph[MAX];
int pass, visited[MAX], parents[MAX], capacity[MAX][MAX], capacity_bkp[MAX][MAX];

bool bfs(int source, int destination) {
	queue<int> q;
	parents[source] = 0;
	visited[source] = ++pass;
	q.push(source);
	while(not q.empty()) {
		auto u = q.front();
		for(auto& v : graph[u]) {
			if(capacity[u][v] and visited[v] != pass) {
				parents[v] = u;
				if(v == destination) {
					return true;
				} else {
					visited[v] = pass;
					q.push(v);
				}
			}
		}
		q.pop();
	}
	return false;
}

int edmonds_karp(int source, int sink) {
	int max_flow = 0;
	while(bfs(source, sink)) {
		int u = sink, path_flow = oo;
		while(parents[u]) {
			path_flow = min(path_flow, capacity[parents[u]][u]);
			u = parents[u];
		}

		u = sink;
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
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n, m;
		scanf("%d %d", &n, &m);
		memset(capacity, 0, sizeof capacity);
		for(int i = 1; i <= m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			graph[u].push_back(v);
			graph[v].push_back(u);
			capacity[u][v] = capacity[v][u] = w;
		}
		memcpy(capacity_bkp, capacity, sizeof capacity_bkp);

		int source = 1, min_cost = oo;
		for(int sink = 2; sink <= n; ++sink) {
			int flow = edmonds_karp(source, sink);
			min_cost = flow ? min(min_cost, flow) : min_cost;
			memcpy(capacity, capacity_bkp, sizeof capacity);
		}
		printf("%d\n", min_cost);

		for(int u = 1; u <= n; ++u) graph[u].clear();
	}
	return 0;
}
