#include <bits/stdc++.h>

#define MAX 20005
#define INF -1

using namespace std;
using ii = pair<int, int>;

vector<ii> graph[MAX];
unsigned dist[MAX];

unsigned dijkstra(int source, int destination) {
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	memset(dist, INF, sizeof dist);
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

	return dist[destination];
}

int main(void) {
	int tests;
	scanf("%d", &tests);
	for(int tc = 1; tc <= tests; ++tc) {
		int n, m, source, destination;
		scanf("%d %d %d %d", &n, &m, &source, &destination);
		for(int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			graph[u].push_back(ii(w, v));
			graph[v].push_back(ii(w, u));
		}

		unsigned min_dist = dijkstra(source, destination);

		printf("Case #%d: ", tc);
		printf(min_dist < INF ? "%d\n" : "unreachable\n", min_dist);

		for(int u = 0; u < n; ++u)
			graph[u].clear();
	}

	return 0;
}
