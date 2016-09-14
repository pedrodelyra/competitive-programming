#include <bits/stdc++.h>

#define INF -1

using namespace std;
using ii = pair<int, int>;
using iii = pair<int, ii>;

int costs[10];
vector<ii> graph[105][10];
unsigned dist[105][10];

set<int> floors[10];

unsigned dijkstra(int n, int destination) {
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	memset(dist, INF, sizeof dist);
	
	for(int i = 1; i <= n; ++i) {
		if(not floors[i].count(0)) continue;

		dist[0][i] = 0;
		pq.push(iii(dist[0][i], ii(0, i)));
	}

	while(not pq.empty()) {
		auto current = pq.top();
		pq.pop();

		int u = current.second.first, current_elevator = current.second.second, current_dist = current.first;

		if(current_dist > dist[u][current_elevator]) continue;

		for(auto& edge : graph[u][current_elevator]) {
			int v = edge.second, w = edge.first;
			if(dist[v][current_elevator] > dist[u][current_elevator] + w) {
				dist[v][current_elevator] = dist[u][current_elevator] + w;
				pq.push(iii(dist[v][current_elevator], ii(v, current_elevator)));
			}
		}

		for(int i = 1; i <= n; ++i) {
			if(i == current_elevator) continue;

			int w = 60;
			if(floors[i].count(u)) {
				if(dist[u][i] > dist[u][current_elevator] + w) {
					dist[u][i] = dist[u][current_elevator] + w;
					pq.push(iii(dist[u][i], ii(u, i)));
				}
			}
		}
	}

	unsigned min_dist = INF;
	for(int i = 1; i <= n; ++i)
		min_dist = min(min_dist, dist[destination][i]);

	return min_dist;
}

int main(void) {
	int n, k;
	while(scanf("%d %d", &n, &k) != EOF) {
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &costs[i]);
		}

		for(int i = 1; i <= n; ++i) {
			char str[1024];
			scanf(" %[^\n]\n", str);

			int x;
			stringstream ss(str);
			while(ss >> x) {
				floors[i].insert(x);
			}

			int last_floor = -1;
			for(auto& floor : floors[i]) {
				if(last_floor >= 0) { 
					int u = floor, v = last_floor;
					graph[u][i].push_back(ii(costs[i] * (u - v), v));
					graph[v][i].push_back(ii(costs[i] * (u - v), u));
				}

				last_floor = floor;
			}
		}

		unsigned min_dist = dijkstra(n, k);
		printf(min_dist < INF ? "%u\n" : "IMPOSSIBLE\n", min_dist);

		for(int i = 0; i <= 100; ++i) {
			for(int j = 1; j <= n; ++j) {
				graph[i][j].clear();
				floors[j].clear();
			}
		}
	}

	return 0;
}
