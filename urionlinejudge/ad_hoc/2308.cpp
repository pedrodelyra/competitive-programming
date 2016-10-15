#include <bits/stdc++.h>

#define oo  0x2f2f2f2f
#define MAX 1024

using namespace std;
using ii = pair<int, int>;

vector<ii> graph[MAX];
int dist[MAX];

int dijkstra(int source) {
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	memset(dist, oo, sizeof dist);
	pq.push(ii(0, source));
	while(not pq.empty()) {
		auto current_state = pq.top(); pq.pop();
		auto current_dist  = current_state.first, u = current_state.second;

		if(current_dist > dist[u]) continue;

		if(u == source && dist[u] < oo) break;

		for(auto& edge : graph[u]) {
			auto w = edge.first, v = edge.second;
			if(dist[v] > current_dist + w) {
				dist[v] = current_dist + w;
				pq.push(ii(dist[v], v));
			}
		}
	}
	return dist[source];
}

int main(void) {
	int n, m, cost[MAX];
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &cost[i]);
	}

	for(int i = 1; i <= m; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back(ii(cost[v] + w, v));
	}

	int ans = oo;
	for(int u = 1; u <= n; ++u) {
		ans = min(ans, dijkstra(u));
	}
	printf("%d\n", ans);

	return 0;
}
