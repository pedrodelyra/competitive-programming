#include <bits/stdc++.h>

#define MAX 25
#define MAX_KEYS (1 << 12)

using namespace std;
using ii = pair<int, int>;

ii coordinates[MAX];
int dist[MAX][MAX], dp[MAX][MAX_KEYS], k;

int tsp(int u, int mask) {
	if(mask == (1 << k) - 1) {
		return dist[u][0];
	} else if(~dp[u][mask]) {
		return dp[u][mask];
	}

	int result = 1 << 30;
	for(int v = 0; v < k; ++v) {
		if(!((mask >> v) & 1)) {
			result = min(result, tsp(v + 1, mask | (1 << v)) + dist[u][v + 1]);
		}
	}

	return dp[u][mask] = result;
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n, m, x, y;
		scanf("%d %d", &n, &m);
		scanf("%d %d", &x, &y);

		coordinates[0] = ii(x, y);

		scanf("%d", &k);
		for(int u = 1; u <= k; ++u) {
			int a, b;
			scanf("%d %d", &a, &b);
			coordinates[u] = ii(a, b);
		}

		for(int u = 0; u <= k; ++u) {
			for(int v = 0; v <= k; ++v) {
				int x0 = coordinates[u].first, y0 = coordinates[u].second;
				int xf = coordinates[v].first, yf = coordinates[v].second;

				dist[u][v] = abs(xf - x0) + abs(yf - y0);
			}
		}

		memset(dp, -1, sizeof dp);
		printf("The shortest path has length %d\n", tsp(0, 0));
	}

	return 0;
}
