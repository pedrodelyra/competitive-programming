#include <stdio.h>
#include <string.h>

#define INF 0x3f3f3f3f
#define _max(a, b) (((a) > (b)) ? (a) : (b))
#define max(a, b, c) _max((a), _max((b), (c)))
#define min(a, b) ((a) < (b) ? (a) : (b))

int dist[128][128];

int main(void) {
	int u, v, n, tc = 0;
	while(scanf("%d %d", &u, &v), n = 0, (u | v)) {
		memset(dist, INF, sizeof dist);
		dist[u][v] = 1;
		n = max(n, u, v);
		while(scanf("%d %d", &u, &v), (u | v)) {
			dist[u][v] = 1;
			n = max(n, u, v);
		}

		int i, j, k;
		for(k = 1; k <= n; ++k) {
			for(i = 1; i <= n; ++i) {
				for(j = 1; j <= n; ++j) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		int total_dist = 0, count = 0;
		for(i = 1; i <= n; ++i) {
			for(j = 1; j <= n; ++j) {
				if(i == j || dist[i][j] == INF) continue;
				total_dist += dist[i][j];
				++count;
			}
		}

		printf("Case %d: average length between pages = %.3lf clicks\n", ++tc, total_dist / (double) count);
	}

	return 0;
}
