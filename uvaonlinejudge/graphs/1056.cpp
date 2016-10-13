#include <bits/stdc++.h>

#define MAX 64
#define INF 0x3f3f3f3f

using namespace std;

int main(void) {
	int n, m, tc = 0;
	while(scanf("%d %d", &n, &m), (n | m)) {
		map<string, int> name_id;
		int k = 0, dist[MAX][MAX];

		memset(dist, INF, sizeof dist);
		for(int u = 1; u <= n; ++u)
			dist[u][u] = 0;

		for(int i = 0; i < m; ++i) {
			char first_name[255], second_name[255];
			scanf(" %s %s", first_name, second_name);
			if(not name_id[first_name]) {
				name_id[first_name] = ++k;
			}

			if(not name_id[second_name]) {
				name_id[second_name] = ++k;
			}

			int u = name_id[first_name], v = name_id[second_name];
			dist[u][v] = dist[v][u] = 1;
		}

		for(int k = 1; k <= n; ++k) {
			for(int u = 1; u <= n; ++u) {
				for(int v = 1; v <= n; ++v) {
					dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
				}
			}
		}

		int max_degree = 0;
		for(int u = 1; u <= n; ++u) {
			for(int v = 1; v <= n; ++v) {
				max_degree = max(max_degree, dist[u][v]);
			}
		}

		printf("Network %d: ", ++tc);
		printf(max_degree < INF ? "%d\n\n" : "DISCONNECTED\n\n", max_degree);
	}

	return 0;
}
