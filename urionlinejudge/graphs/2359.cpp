#include <bits/stdc++.h>

#define MAX 1024
#define oo  0x2f2f2f2f

using namespace std;
using ii = pair<int, int>;

vector<ii> graph[MAX];
int dist[MAX];

int dijkstra(vector<int>& hospitals) {
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	memset(dist, oo, sizeof dist);
	for(auto& h : hospitals) {
		pq.push(ii(dist[h] = 0, h));
	}
	int max_dist = 0;
	while(not pq.empty()) {
		auto current_state = pq.top(); pq.pop();
		auto current_dist = current_state.first, u = current_state.second;

		if(current_dist > dist[u]) continue;

		max_dist = max(max_dist, current_dist);
		for(auto& edge : graph[u]) {
			int w = edge.first, v = edge.second;
			if(dist[v] > dist[u] + w) {
				pq.push(ii(dist[v] = dist[u] + w, v));
			}
		}
	}
	return max_dist;
}

int main(void) {
	int n, m, k;
	while(~scanf("%d %d %d", &n, &m, &k)) {
		for(int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			graph[u].push_back(ii(w, v));
			graph[v].push_back(ii(w, u));
		}
		vector<int> hospitals;
		for(int i = 0; i < k; ++i) {
			int h;
			scanf("%d", &h);
			hospitals.push_back(h);
		}
		printf("%d\n", dijkstra(hospitals));
		for(int u = 1; u <= n; ++u) {
			graph[u].clear();
		}
	}
	return 0;
}
