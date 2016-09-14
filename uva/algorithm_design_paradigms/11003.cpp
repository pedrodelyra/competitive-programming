#include <bits/stdc++.h>

#define MAX 1024
#define MAX_WEIGHT 3005
#define INF 0x3f3f3f3f

using namespace std;

int n, capacities[MAX], weights[MAX], dp[MAX][MAX_WEIGHT];

int max_stack(int u, int w) {
	if(u == 0) {
		return 0;
	} else if(capacities[u] < w) {
		return max_stack(u - 1, w);
	} else if(~dp[u][w]) {
		return dp[u][w];
	}

	return dp[u][w] = max(max_stack(u - 1, w + weights[u]) + 1, max_stack(u - 1, w));
}

int main(void) {
	while(scanf("%d", &n), n) {
		for(int i = 1; i <= n; ++i) {
			scanf("%d %d", &weights[i], &capacities[i]);
		}

		memset(dp, -1, sizeof dp);
		printf("%d\n", max_stack(n, 0));
	}

	return 0;
}
