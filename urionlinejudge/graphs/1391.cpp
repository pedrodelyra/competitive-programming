#include <bits/stdc++.h>

#define MAX 512
#define INF -1
#define ORIGINAL 0
#define REVERSED 1

using namespace std;
using ii = pair<int, int>;

vector<ii> graph[2][MAX];
unsigned dist[2][MAX], forbidden_edge[MAX][MAX];

unsigned dijkstra(int source, int destination, int id) {
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	memset(dist[id], INF, sizeof dist[id]);
	dist[id][source] = 0;
	pq.push(ii(dist[id][source], source));
	while(not pq.empty()) {
		auto current_state = pq.top(); pq.pop();
		int u = current_state.second, current_dist = current_state.first;

		if(current_dist > dist[id][u]) continue;

		if(u == destination) break;

		for(auto& edge : graph[id][u]) {
			unsigned v = edge.second, w = edge.first;
			if(not forbidden_edge[u][v] && dist[id][v] > dist[id][u] + w) {
				dist[id][v] = dist[id][u] + w;
				pq.push(ii(dist[id][v], v));
			}
		}
	}

	return dist[id][destination];
}

int main(void) {
	int n, m;
	while(scanf("%d %d", &n, &m), n | m) {
		unsigned source, destination, shortest_path;
		scanf("%u %u", &source, &destination);

		memset(forbidden_edge, false, sizeof forbidden_edge);
		for(int i = 1; i <= m; ++i) {
			unsigned u, v, w;
			scanf("%u %u %u", &u, &v, &w);
			graph[ORIGINAL][u].push_back(ii(w, v));
			graph[REVERSED][v].push_back(ii(w, u));
		}

		shortest_path = dijkstra(source, destination, ORIGINAL);
		dijkstra(destination, source, REVERSED);

		for(int u = 0; u < n; ++u) {
			for(auto& edge : graph[ORIGINAL][u]) {	
				unsigned v = edge.second, w = edge.first;
				if(dist[ORIGINAL][u] + dist[REVERSED][v] + w == shortest_path) forbidden_edge[u][v] = true;
			}
		}

		unsigned almost_shortest_path = dijkstra(source, destination, ORIGINAL);
		printf("%d\n", almost_shortest_path);

		for(int u = 0; u < n; ++u) {
			graph[ORIGINAL][u].clear();
			graph[REVERSED][u].clear();
		}
	}

	return 0;
}
