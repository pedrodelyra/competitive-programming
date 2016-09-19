#include <bits/stdc++.h>

#define MAX 128
#define INF 1e15
#define EPS 1e-8

using namespace std;
using ddd = tuple<double, double, double>;

double dist[MAX][MAX];

int main(void) {
	int n;
	while(scanf("%d", &n), n) {
		ddd anthens[n + 1];
		for(int i = 1; i <= n; ++i) {
			int x, y, r;
			scanf("%d %d %d", &x, &y, &r);
			anthens[i] = ddd(x, y, r);
		}

		for(int u = 1; u < n; ++u) {
			for(int v = u + 1; v <= n; ++v) {
				if(u == v) continue;

				double x1, y1, r1, x2, y2, r2;
				tie(x1, y1, r1) = anthens[u];
				tie(x2, y2, r2) = anthens[v];

				double curr_dist = hypot(x1 - x2, y1 - y2);
				dist[u][v] = curr_dist < r1 + EPS ? curr_dist : INF;
				dist[v][u] = curr_dist < r2 + EPS ? curr_dist : INF;
			}
		}

		for(int k = 1; k <= n; ++k) {
			for(int u = 1; u <= n; ++u) {
				for(int v = 1; v <= n; ++v) {
					dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
				}
			}
		}

		int q;
		scanf("%d", &q);
		while(q--) {
			int source, destination;
			scanf("%d %d", &source, &destination);
			printf(dist[source][destination] < INF ? "%d\n" : "-1\n", (int) dist[source][destination]);
		}
	}

	return 0;
}
