#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define MAX 100005

using namespace std;
using ii = pair<int, int>;
using edge = pair<int, ii>;

vector<ii> original_graph[MAX], reversed_graph[MAX];
int source_dist[MAX], destination_dist[MAX];

void dijkstra(int source, vector<ii> (&graph)[MAX], int (&dist)[MAX]) {
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	memset(dist, INF, sizeof dist);
	dist[source] = 0;
	pq.push(ii(dist[source], source));
	while(not pq.empty()) {
		auto current_state = pq.top();
		pq.pop();

		int current_dist = current_state.first, u = current_state.second;

		if(current_dist > dist[u]) continue;

		for(auto& current_edge : graph[u]) {
			int w = current_edge.first, v = current_edge.second;
			if(dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push(ii(dist[v], v));
			}
		}
	}
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n, m, source, destination, total_money;
		scanf("%d %d %d %d %d", &n, &m, &source, &destination, &total_money);

		priority_queue<edge> edges;
		for(int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			original_graph[u].push_back(ii(w, v));
			reversed_graph[v].push_back(ii(w, u));
			edges.push(edge(w, ii(u, v)));
		}

		dijkstra(source, original_graph, source_dist);
		dijkstra(destination, reversed_graph, destination_dist);

		int max_edge = -1;
		while(not edges.empty() && !~max_edge) {
			auto& current_edge = edges.top();
			int w = current_edge.first, u = current_edge.second.first, v = current_edge.second.second;
			int path_cost = source_dist[u] + destination_dist[v] + w;

			if(path_cost <= total_money) max_edge = w;

			edges.pop();
		}

		printf("%d\n", max_edge);

		for(int u = 1; u <= n; ++u) {
			original_graph[u].clear();
			reversed_graph[u].clear();
		}
	}

	return 0;
}
