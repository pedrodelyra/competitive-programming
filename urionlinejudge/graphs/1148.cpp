#include <bits/stdc++.h>

#define MAX 512

using namespace std;

unsigned dist[MAX][MAX];

int main(void) {
	int n, m;
	while(scanf("%d %d", &n, &m), n | m) {
		memset(dist, -1, sizeof dist);
		for(int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			if(~dist[v][u]) {
				dist[u][v] = dist[v][u] = 0;
			} else {
				dist[u][v] = w;
			}
		}

		for(int k = 1; k <= n; ++k) {
			for(int u = 1; u <= n; ++u) {
				for(int v = 1; v <= n; ++v) {
					if(~dist[u][k] && ~dist[k][v])
						dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
				}
			}
		}

		int k;
		scanf("%d", &k);
		while(k--) {
			int source, destination;
			scanf("%d %d", &source, &destination);
			printf(~dist[source][destination] ? "%d\n" : "Nao e possivel entregar a carta\n", dist[source][destination]);
		}
		printf("\n");
	}

	return 0;
}
