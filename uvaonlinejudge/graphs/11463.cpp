#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int dist[128][128];

int main(void) {
	int tests;
	scanf("%d", &tests);
	for(int tc = 1; tc <= tests; ++tc) {
		int n, m;
		scanf("%d %d", &n, &m);

		memset(dist, INF, sizeof dist);
		for(int u = 0; u < n; ++u)
			dist[u][u] = 0;

		for(int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			dist[u][v] = dist[v][u] = 1;
		}

		for(int k = 0; k < n; ++k) {
			for(int u = 0; u < n; ++u) {
				for(int v = 0; v < n; ++v) {
					dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
				}
			}
		}

		int s, d, max_dist = 0;
		scanf("%d %d", &s, &d);
		for(int u = 0; u < n; ++u) {
			max_dist = max(max_dist, dist[s][u] + dist[u][d]);
		}

		printf("Case %d: %d\n", tc, max_dist);
	}

	return 0;
}
