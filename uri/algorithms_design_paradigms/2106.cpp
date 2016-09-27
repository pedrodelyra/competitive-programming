#include <bits/stdc++.h>

#define MAX 18
#define oo (1 << 30)

using namespace std;

int n, VISITED = 1, costs[MAX][MAX], visited[MAX][1 << MAX], dp[MAX][1 << MAX];

int min_cost(int u, int mask) {
	if(u == n) {
		return 0;
	} else if(visited[u][mask] == VISITED) {
		return dp[u][mask];
	}

	int ans = oo;
	for(int i = 0; i < n; ++i) {
		if((mask >> i) & 1) continue;

		ans = min(ans, min_cost(u + 1, mask | (1 << i)) + costs[i][u]);
	}

	return visited[u][mask] = VISITED, dp[u][mask] = ans;
}

int main(void) {
	while(scanf("%d", &n), n) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				scanf("%d", &costs[i][j]);
			}
		}

		printf("%d\n", min_cost(0, 0));
		VISITED++;
	}
	return 0;
}
