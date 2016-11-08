#include <bits/stdc++.h>

using namespace std;

int A[512], exists[512], dist[512][512];

int main(void) {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			scanf("%d", &dist[i][j]);
		}
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &A[i]);
	}

	vector<long long> ans(n + 1);
	for(int k = n; k >= 1; --k) {
		exists[A[k]] = true;
		for(int u = 1; u <= n; ++u) {
			for(int v = 1; v <= n; ++v) {
				dist[u][v] = min(dist[u][v], dist[u][A[k]] + dist[A[k]][v]);
			}
		}
		long long sum = 0;
		for(int u = 1; u <= n; ++u) {
			if(not exists[u]) continue;
			for(int v = 1; v <= n; ++v) {
				if(not exists[v]) continue;

				sum += dist[u][v];
			}
		}
		ans[k] = sum;
	}

	for(int i = 1; i <= n; ++i) {
		printf("%lld ", ans[i]);
	}
	printf("\n");
	return 0;
}
