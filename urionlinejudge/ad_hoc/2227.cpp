#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, m, tc = 0;
	while(scanf("%d %d", &n, &m), n | m) {
		int max_traffic = 0, traffic[n + 1];
		memset(traffic, 0, sizeof traffic);
		for(int i = 1; i <= m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			max_traffic = max(max_traffic, ++traffic[u]);
			max_traffic = max(max_traffic, ++traffic[v]);
		}

		printf("Teste %d\n", ++tc);
		for(int i = 1; i <= n; ++i) {
			if(traffic[i] == max_traffic) {
				printf("%d ", i);
			}
		}
		printf("\n\n");
	}
	return 0;
}
