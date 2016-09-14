#include <bits/stdc++.h>

#define MAX 1024
#define MAX_GAS 128
#define INF (1 << 30)

using namespace std;
using ii = pair<int, int>;
using iii = pair<int, ii>;

vector<ii> graph[MAX];
int dist[MAX][MAX_GAS], cost[MAX], state[MAX][MAX_GAS], VISITED = 1;

int dijkstra(int source, int destination, int fuel_capacity) {
	int min_dist = INF;
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	dist[source][0] = 0;
	state[source][0] = VISITED;
	pq.push(iii(dist[source][0], ii(source, 0)));
	while(not pq.empty()) {
		auto current = pq.top();
		pq.pop();
		int u = current.second.first, current_gas = current.second.second, current_dist = current.first;

		if(current_dist > dist[u][current_gas]) continue;

		if(u == destination) min_dist = min(min_dist, dist[u][current_gas]);

		if(current_gas < fuel_capacity) {
			if(state[u][current_gas + 1] != VISITED || dist[u][current_gas + 1] > dist[u][current_gas] + cost[u]) {
				dist[u][current_gas + 1] = dist[u][current_gas] + cost[u];
				state[u][current_gas + 1] = VISITED;
				pq.push(iii(dist[u][current_gas + 1], ii(u, current_gas + 1)));
			}
		}

		for(auto& edge : graph[u]) {
			int v = edge.second, w = edge.first;
			if(current_gas >= w && (state[v][current_gas - w] != VISITED || dist[v][current_gas - w] > dist[u][current_gas])) {
				dist[v][current_gas - w] = dist[u][current_gas];
				state[v][current_gas - w] = VISITED;
				pq.push(iii(dist[v][current_gas - w], ii(v, current_gas - w)));
			}
		}
	}

	++VISITED;
	return min_dist;
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &cost[i]);
	}

	for(int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back(ii(w, v));
		graph[v].push_back(ii(w, u));
	}

	int q;
	scanf("%d", &q);
	while(q--) {
		int source, destination, fuel_capacity;
		scanf("%d %d %d", &fuel_capacity, &source, &destination);

		int min_cost = dijkstra(source, destination, fuel_capacity);
		printf(min_cost < INF ? "%d\n" : "impossible\n", min_cost);
	}

	return 0;
}
