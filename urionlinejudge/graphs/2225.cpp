#include <bits/stdc++.h>

#define MAX   15
#define MAX_K 5
#define oo    0x2f2f2f2f

using namespace std;
using ii = pair<int, int>;
using state = tuple<int, int, int, int>;

vector<ii> graph[MAX];
int dist[MAX][1 << MAX][MAX_K + 1];

int dijkstra(int n, int m, int k) {
	priority_queue<state, vector<state>, greater<state>> pq;
	memset(dist, oo, sizeof dist);
	pq.push(state(dist[0][1][0] = 0, 0, 1, 0));
	while(not pq.empty()) {
		auto current_state = pq.top(); pq.pop();
		int current_dist, u, mask, x;
		tie(current_dist, u, mask, x) = current_state;

		if(current_dist > dist[u][mask][x]) continue;

		if(1 << n == mask + 1) return current_dist;

		for(auto& edge : graph[u]) {
			int w = edge.first, v = edge.second;
			if(dist[v][mask | (1 << v)][x] > dist[u][mask][x] + w) {
				pq.push(state(dist[v][mask | (1 << v)][x] = dist[u][mask][x] + w, v, mask | (1 << v), x));
			}
		}
		for(int v = 0; x < k and v < n; ++v) {
			if(dist[v][mask | (1 << v)][x + 1] > dist[u][mask][x]) {
				pq.push(state(dist[v][mask | (1 << v)][x + 1] = dist[u][mask][x], v, mask | (1 << v), x + 1));
			}
		}
	}
	return oo;
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		for(int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			graph[u - 1].push_back(ii(w, v - 1));
			graph[v - 1].push_back(ii(w, u - 1));
		}
		int ans = dijkstra(n, m, k);
		printf("%d\n", ans < oo ? ans : -1);
		for(int u = 0; u < n; ++u) graph[u].clear();
	}
	return 0;
}
