#include <bits/stdc++.h>

#define MAX 128
#define oo  0x3f3f3f3f

using namespace std;

int  n, m, k, grid[MAX][MAX], sum[MAX][MAX], dp[MAX][MAX];
char patterns[MAX][MAX];
bool ok[MAX][MAX];

int solve(int row, int last_pattern) {
	if(row > n) {
		return 0;
	} else if(~dp[row][last_pattern]) {
		return dp[row][last_pattern];
	}
	int ans = -oo;
	for(int i = 1; i <= k; ++i) {
		if(ok[i][last_pattern]) {
			ans = max(ans, solve(row + 1, i) + sum[row][i]);
		}
	}
	return dp[row][last_pattern] = ans;
}

int main(void) {
	map<char, int> id = {{'-', 1}, {'+', 2}};
	while(scanf("%d %d", &n, &m), n | m) {
		memset(grid, '.', sizeof grid);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				scanf("%d", &grid[i][j]);
			}
		}

		scanf("%d", &k);
		for(int i = 1; i <= k; ++i) {
			scanf(" %s", patterns[i] + 1);
		}
		memset(ok, true, sizeof ok);
		for(int i = 1; i <= k; ++i) {
			for(int j = i; j <= k; ++j) {
				for(int k = 1; k <= m; ++k) {
					ok[i][j] = ok[i][j] and ((id[patterns[i][k]] ^ id[patterns[j][k]]) or patterns[i][k] == '.' or patterns[j][k] == '.');
				}
				ok[j][i] = ok[i][j];
			}
		}
		memset(sum, 0, sizeof sum);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= k; ++j) {
				for(int k = 1; k <= m; ++k) {
					if(patterns[j][k] == '+') {
						sum[i][j] += grid[i][k];
					} else if(patterns[j][k] == '-') {
						sum[i][j] -= grid[i][k];
					}
				}
			}
		}
		memset(dp, -1, sizeof dp);
		printf("%d\n", solve(1, 0));
	}
	return 0;
}
