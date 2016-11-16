#include <bits/stdc++.h>

#define MAX	 105
#define MAX_TIME 6005
#define oo	 0x3f3f3f3f

using namespace std;
using ii  = pair<int, int>;
using iii = tuple<int, int, int>;

vector<iii> graph[MAX];
int dist[MAX][MAX_TIME];

ii dijkstra(int source, int destination, int timelimit) {
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	memset(dist, oo, sizeof dist);
	pq.push(iii(dist[source][0] = 0, source, 0));
	while(not pq.empty()) {
		auto current_state = pq.top(); pq.pop();
		int current_dist, u, t;
		tie(current_dist, u, t) = current_state;

		if(current_dist > dist[u][t]) continue;

		if(u == destination) return ii(dist[u][t], t);

		for(auto& edge : graph[u]) {
			int v, w, dt;
			tie(v, w, dt) = edge;
			if(t + dt <= timelimit and dist[v][t + dt] > dist[u][t] + w) {
				pq.push(iii(dist[v][t + dt] = dist[u][t] + w, v, t + dt));
			}
		}
	}
	return ii(-1, -1);
}

int main(void) {
	int n, m, tc = 0;
	while(scanf("%d %d", &n, &m), n | m) {
		for(int i = 0; i < m; ++i) {
			int u, v, w, t;
			scanf("%d %d %d %d", &u, &v, &w, &t);
			graph[u].push_back(iii(v, w, t));
		}

		int k;
		scanf("%d", &k);
		printf("Instancia %d\n", ++tc);
		while(k--) {
			int source, destination, timelimit;
			scanf("%d %d %d", &source, &destination, &timelimit);
			auto ans = dijkstra(source, destination, timelimit);
			if(~ans.first and ~ans.second) {
				printf("Possivel - %d km, %d min\n", ans.first, ans.second);
			} else {
				printf("Impossivel\n");
			}
		}
		printf("\n");
		for(int i = 1; i <= n; ++i) {
			graph[i].clear();
		}
	}

	return 0;
}
