#include <bits/stdc++.h>

#define MAX_SZ 128
#define MAX_NEG 10
#define INF (1 << 30)
#define UP 0
#define RIGHT 1
#define LEFT 2

using namespace std;

int n, k, tc, grid[MAX_SZ][MAX_SZ], dp[3][MAX_SZ][MAX_SZ][MAX_NEG];

bool valid_position(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

int max_sum(int dir, int x, int y, int neg) {
	if(neg > k || !valid_position(x, y)) {
		return -INF;
	} else if(x == n && y == n) {
		return dp[dir][x][y][neg] = grid[x][y];
	} else if(~dp[dir][x][y][neg]) {
		return dp[dir][x][y][neg];
	}

	int left, right, down;
	left  = dir != LEFT ? max_sum(RIGHT, x, y - 1, neg + (grid[x][y - 1] < 0)) : -INF;
	right = dir != RIGHT ? max_sum(LEFT, x, y + 1, neg + (grid[x][y + 1] < 0)) : -INF;
	down  = max_sum(UP, x + 1, y, neg + (grid[x + 1][y] < 0));

	return dp[dir][x][y][neg] = max(left, max(right, down)) + grid[x][y];
}

int main(void) {
	while(scanf("%d %d", &n, &k), (n | k)) {
		memset(dp, -1, sizeof dp);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				scanf("%d", &grid[i][j]);
			}
		}

		int result = max_sum(UP, 1, 1, grid[1][1] < 0);
		bool possible = false;
		for(int i = 0; i <= k; ++i) {
			possible = possible || ~dp[UP][n][n][i] || ~dp[LEFT][n][n][i] || ~dp[RIGHT][n][n][i];
		};

		printf("Case %d: ", ++tc);
		printf(possible ? "%d\n" : "impossible\n", result);
	}

	return 0;
}
