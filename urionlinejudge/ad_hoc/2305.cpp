#include <bits/stdc++.h>

#define MAX 1024

using namespace std;

int sum[MAX][MAX];

int main(void) {
	int n, m, x, y;
	scanf("%d %d %d %d", &n, &m, &x, &y), --x, --y;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%d", &sum[i][j]);
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}

	int ans = 0;
	for(int i = 1; i + x <= n; ++i) {
		for(int j = 1; j + y <= m; ++j) {
			ans = max(ans, sum[i + x][j + y] - sum[i - 1][j + y] - sum[i + x][j - 1] + sum[i - 1][j - 1]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
