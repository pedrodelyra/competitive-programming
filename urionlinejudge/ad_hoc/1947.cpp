#include <bits/stdc++.h>

#define MAX 16
#define oo  0x3f3f3f3f

using namespace std;
using ii = pair<int, int>;

vector<ii> graph[1 << MAX];
int k, costs[MAX], dist[MAX][MAX], dp[MAX][1 << MAX];

int dijkstra(int source, int destination) {
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	int min_dist[1 << MAX];
	memset(min_dist, oo, sizeof min_dist);
	pq.push(ii(min_dist[source] = 0, source));
	while(not pq.empty()) {
		auto current = pq.top(); pq.pop();
		auto current_dist = current.first, u = current.second;

		if(current_dist > min_dist[u]) continue;

		if(u == destination) break;

		for(auto& edge : graph[u]) {
			int v = edge.second, w = edge.first;
			if(min_dist[v] > min_dist[u] + w) {
				pq.push(ii(min_dist[v] = min_dist[u] + w, v));
			}
		}
	}
	return min_dist[destination];
}

int tsp(int u, int mask) {
	if(1 << k + 1 == mask + 1) {
		return costs[u] + dist[u][0];
	} else if(~dp[u][mask]) {
		return dp[u][mask];
	}
	int ans = oo;
	for(int v = 1; v <= k; ++v) {
		if((mask >> v) & 1) continue;
		ans = min(ans, tsp(v, mask | (1 << v)) + dist[u][v]);
	}
	return dp[u][mask] = ans + costs[u];
}

int main(void) {
	int n, m;
	scanf("%d %d %d", &n, &m, &k);
	vector<ii> tasks(k + 1);
	for(int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back(ii(w, v));
		graph[v].push_back(ii(w, u));
	}
	for(int i = 1; i <= k; ++i) {
		scanf("%d %d", &tasks[i].first, &tasks[i].second);
		costs[i] = dijkstra(tasks[i].first, tasks[i].second);
		dist[0][i] = dijkstra(1, tasks[i].first);
		dist[i][0] = dijkstra(tasks[i].second, 1);
	}
	for(int i = 1; i <= k; ++i) {
		for(int j = 1; j <= k; ++j) {
			if(i != j) {
				dist[i][j] = dijkstra(tasks[i].second, tasks[j].first);
			}
		}
	}
	memset(dp, -1, sizeof dp);
	printf("%d\n", tsp(0, 1));
	return 0;
}
