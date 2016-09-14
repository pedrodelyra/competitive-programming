#include <bits/stdc++.h>

#define MAX 35
#define INF -1

using namespace std;

unsigned dist1[MAX][MAX], dist2[MAX][MAX];

int main(void) {
	int n;
	while(scanf("%d", &n), n) {
		memset(dist1, INF, sizeof dist1);
		memset(dist2, INF, sizeof dist2);
		for(int i = 0; i < n; ++i) {
			int w;
			char a, b, c, d;
			scanf(" %c %c %c %c %d", &a, &b, &c, &d, &w);

			c = c - 'A' + 1;
			d = d - 'A' + 1;

			if(a == 'Y') {
				if(b == 'U') {
					dist1[c][d] = w;
				} else {
					dist1[c][d] = w;
					dist1[d][c] = w;
				}
			} else {
				if(b == 'U') {
					dist2[c][d] = w;
				} else {
					dist2[c][d] = w;
					dist2[d][c] = w;
				}
			}
		}

		for(int u = 1; u <= 26; ++u) {
			dist1[u][u] = dist2[u][u] = 0;
		}

		for(int k = 1; k <= 26; ++k) {
			for(int u = 1; u <= 26; ++u) {
				for(int v = 1; v <= 26; ++v) {
					if(~dist1[u][k] && ~dist1[k][v])
						dist1[u][v] = min(dist1[u][v], dist1[u][k] + dist1[k][v]);
				}
			}
		}

		for(int k = 1; k <= 26; ++k) {
			for(int u = 1; u <= 26; ++u) {
				for(int v = 1; v <= 26; ++v) {
					if(~dist2[u][k] && ~dist2[k][v])
						dist2[u][v] = min(dist2[u][v], dist2[u][k] + dist2[k][v]);
				}
			}
		}

		unsigned min_dist = INF;
		char source1, source2;
		scanf(" %c %c", &source1, &source2);
		source1 = source1 - 'A' + 1;
		source2 = source2 - 'A' + 1;
		for(int u = 1; u <= 26; ++u) {
			if(~dist1[source1][u] && ~dist2[source2][u]) {
				if(min_dist > dist1[source1][u] + dist2[source2][u])
					min_dist = dist1[source1][u] + dist2[source2][u];
			}
		}

		if(min_dist == INF) {
			printf("You will never meet.\n");
			continue;
		}

		printf("%d", min_dist);
		for(int u = 1; u <= 26; ++u) {
			if(~dist1[source1][u] && ~dist2[source2][u]) {
				if(min_dist == dist1[source1][u] + dist2[source2][u])
					printf(" %c", 'A' + u - 1);
			}	
		}

		printf("\n");
	}

	return 0;
}
