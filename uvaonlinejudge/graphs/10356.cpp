#include <bits/stdc++.h>

#define MAX 512
#define INF 0x3f3f3f3f

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

vector<ii> graph[MAX];
int dist[MAX][2], riding_bike = 1;

int dijkstra(int source, int destination) {
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	memset(dist, INF, sizeof dist);
	dist[source][riding_bike] = 0;
	pq.push(iii(dist[source][riding_bike], source, riding_bike));
	while(not pq.empty()) {
		auto current_state = pq.top();
		pq.pop();
		int current_dist, u, state;
		tie(current_dist, u, state) = current_state;

		if(current_dist > dist[u][state]) continue;

		for(auto& edge : graph[u]) {
			int w = edge.first, v = edge.second;
			if(dist[v][!state] > dist[u][state] + w) {
				dist[v][!state] = dist[u][state] + w;
				pq.push(iii(dist[v][!state], v, !state));
			}
		}
	}

	return dist[destination][riding_bike];
}

int main(void) {
	int n, m, tc = 0;
	while(scanf("%d %d", &n, &m) != EOF) {
		for(int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			graph[u].push_back(ii(w, v));
			graph[v].push_back(ii(w, u));
		}

		int min_dist = dijkstra(0, n - 1);
		printf("Set #%d\n", ++tc);
		printf(min_dist < INF ? "%d\n" : "?\n", min_dist);

		for(int u = 0; u < n; ++u)
			graph[u].clear();
	}

	return 0;
}
