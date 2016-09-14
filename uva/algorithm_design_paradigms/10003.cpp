#include <bits/stdc++.h>

#define MAX 1024
#define INF 0x3f3f3f3f

using namespace std;

int n, bars[MAX], dp[MAX][MAX];

int min_cut(int i, int j) {
	if(i + 1 >= j) {
		return 0;
	} if(~dp[i][j]) {
		return dp[i][j];
	}

	int result = INF, bar_size = bars[j] - bars[i];
	for(int k = i + 1; k < j; ++k) {
		result = min(result, min_cut(i, k) + min_cut(k, j) + bar_size);
	}

	return dp[i][j] = result;
}

int main(void) {
	int bar_size;
	while(scanf("%d", &bar_size), bar_size) {
		scanf("%d", &n);
		bars[0] = 0, bars[n + 1] = bar_size;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &bars[i]);
		}

		memset(dp, -1, sizeof dp);
		printf("The minimum cutting is %d.\n", min_cut(0, n + 1));
	}

	return 0;
}
