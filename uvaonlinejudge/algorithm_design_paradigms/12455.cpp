#include <cstdio>
#include <cstring>

#define MAX 25
#define MAX_SUM 1024

int array[MAX], dp[MAX][MAX_SUM], sum;

bool has_sum(int n, int s) {
	if(s == sum) {
		return true;
	} else if(n == 0) {
		return false;
	} else if(~dp[n][s]) {
		return dp[n][s];
	}

	return has_sum(n - 1, s) || has_sum(n - 1, s + array[n]);
}

int main(void) {
	int n, tc;
	scanf("%d", &tc);
	while(tc--) {
		scanf("%d %d", &sum, &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &array[i]);
		}

		memset(dp, -1, sizeof dp);
		printf(has_sum(n, 0) ? "YES\n" : "NO\n");
	}

	return 0;
}
