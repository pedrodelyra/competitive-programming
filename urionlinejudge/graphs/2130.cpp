#include <bits/stdc++.h>

#define MAX 128
#define INF -1

using namespace std;

unsigned dist[MAX][MAX][MAX];

int main(void) {
	int n, m, tc = 0;
	while(~scanf("%d %d", &n, &m)) {
		memset(dist, INF, sizeof dist);
		for(int i = 0; i < m; ++i) {
			unsigned u, v, w;
			scanf("%u %u %u", &u, &v, &w);
			dist[u][v][0] = min(dist[u][v][0], w);
		}

		for(int u = 1; u <= n; ++u) dist[u][u][0] = 0;

		for(int k = 1; k <= n; ++k) {
			for(int u = 1; u <= n; ++u) {
				for(int v = 1; v <= n; ++v) {
					dist[u][v][k] = min(dist[u][v][k], dist[u][v][k - 1]);

					if(~dist[u][k][k - 1] && ~dist[k][v][k - 1])
						dist[u][v][k] = min(dist[u][v][k], dist[u][k][k - 1] + dist[k][v][k - 1]);
				}
			}
		}

		int q;
		scanf("%d", &q);
		printf("Instancia %d\n", ++tc);
		while(q--) {
			int source, destination, t;
			scanf("%d %d %d", &source, &destination, &t);
			printf("%d\n", dist[source][destination][t]);
		}
		printf("\n");
	}

	return 0;
}
