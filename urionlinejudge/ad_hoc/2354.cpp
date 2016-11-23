#include <bits/stdc++.h>

#define MAX 128

using namespace std;

vector<int> graph[MAX];
int visited[MAX], parents[MAX], votes[MAX], voted[MAX][MAX], capacity[MAX][MAX];

bool bfs(int source, int destination) {
	queue<int> q;
	memset(visited, false, sizeof visited);
	parents[source] = -1;
	visited[source] = true;
	q.push(source);
	while(not q.empty()) {
		int u = q.front();
		for(auto& v : graph[u]) {
			if(not visited[v] and capacity[u][v]) {
				parents[v] = u;
				visited[v] = true;
				q.push(v);
			}
		}
		q.pop();
	}
	return visited[destination] == true;
}

int edmonds_karp(int source, int sink) {
	int max_flow = 0;
	while(bfs(source, sink)) {
		int u = sink, path_flow = 1 << 30;
		while(~parents[u]) {
			path_flow = min(path_flow, capacity[parents[u]][u]);
			u = parents[u];
		}

		u = sink;
		while(~parents[u]) {
			capacity[parents[u]][u] -= path_flow;
			capacity[u][parents[u]] += path_flow;
			u = parents[u];
		}
		max_flow += path_flow;
	}
	return max_flow;
}

int main(void) {
	int n;
	scanf("%d", &n);
	const int source = 0, sink = n << 1 | 1;
	for(int u = 1; u <= n; ++u) {
		int x, y;
		scanf("%d %d", &x, &y);
		graph[u].push_back(x + n);
		graph[x + n].push_back(u);
		voted[u][x] = true;

		graph[u].push_back(y + n);
		graph[y + n].push_back(u);
		voted[u][y] = true;

		graph[source].push_back(u);
		graph[u].push_back(source);

		graph[u + n].push_back(sink);
		graph[sink].push_back(u + n);

		votes[x]++;
		votes[y]++;
	}

	int wins = 0;
	for(int ww = 1; ww <= n; ++ww) {
		memset(capacity, 0, sizeof capacity);
		for(int u = 1; u <= n; ++u) {
			if(u == ww) continue;

			if(capacity[source][u] = !voted[u][ww]) {
				for(auto& v : graph[u]) {
					capacity[u][v] = 1;
				}
			}
			capacity[u + n][sink] = max(votes[ww] - (1 << voted[ww][u]), 0);
		}
		if(edmonds_karp(source, sink) != n - votes[ww] - 1) {
			++wins;
		}
	}
	printf("%d\n", wins);
	return 0;
}
