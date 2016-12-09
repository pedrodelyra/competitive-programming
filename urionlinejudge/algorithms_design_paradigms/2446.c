#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool dp[2][100005];

int cmp(const void* a, const void* b) { return *(int *) a - *(int *) b; }

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	int i, j, k, coins[1024];
	for(i = 1; i <= m; ++i) {
		scanf("%d", &coins[i]);
	}
	qsort(coins + 1, m, sizeof(int), cmp);
	for(i = 1, k = 1; i <= m; ++i, k ^= 1) {
		dp[k ^ 1][0] = true;
		for(j = coins[i]; j <= n; ++j) {
			dp[k][j] |= dp[k ^ 1][j - coins[i]];
		}
		memcpy(dp[k ^ 1], dp[k], sizeof dp[k]);
	}
	printf(dp[k][n] ? "S\n" : "N\n");
	return 0;
}
