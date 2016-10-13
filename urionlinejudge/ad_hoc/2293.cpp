#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	int grid[n + 1][m + 1];
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%d", &grid[i][j]);
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		int sum = 0;
		for(int j = 1; j <= m; ++j) {
			sum += grid[i][j];
		}
		ans = max(ans, sum);
	}

	for(int j = 1; j <= m; ++j) {
		int sum = 0;
		for(int i = 1; i <= n; ++i) {
			sum += grid[i][j];
		}
		ans = max(ans, sum);
	}

	printf("%d\n", ans);
	
	return 0;
}
