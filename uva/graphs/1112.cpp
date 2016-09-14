#include <bits/stdc++.h>

#define MAX 128

using namespace std;
using ii = pair<int, int>;

vector<ii> graph[MAX];
unsigned dist[MAX];

int dijkstra(int source) {
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	memset(dist, -1, sizeof dist);
	dist[source] = 0;
	pq.push(ii(dist[source], source));

	while(not pq.empty()) {
		auto current = pq.top();
		pq.pop();

		int u = current.second, current_dist = current.first;

		if(current_dist > dist[u]) continue;

		for(auto& edge : graph[u]) {
			int v = edge.second, w = edge.first;
			if(dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push(ii(dist[v], v));
			}
		}
	}
}

int main(void) {
	int tc, status = 0;
	scanf("%d", &tc);
	while(tc--) {
		int n, m, t, source;
		scanf("%d %d %d %d", &n, &source, &t, &m);
		for(int i = 1; i <= m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			graph[u].push_back(ii(w, v));
			graph[v].push_back(ii(w, u));
		}

		dijkstra(source);

		int mice = 0;
		for(int u = 1; u <= n; ++u) {
			if(dist[u] <= t) ++mice;
		}

		if(not status) { status = 1; } else { printf("\n"); }
		printf("%d\n", mice);

		for(int u = 1; u <= n; ++u)
			graph[u].clear();
	}

	return 0;
}
