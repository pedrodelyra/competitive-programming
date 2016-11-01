#include <bits/stdc++.h>

#define MAX 1024
#define oo  0x2f2f2f2f

using namespace std;

int n, grid[MAX][MAX], dp[2][MAX][MAX], factors[2][MAX][MAX];

void compute_factors(int x, int y) {
	int n = grid[x][y];
	while(n and n % 2 == 0) {
		factors[0][x][y]++;
		n /= 2;
	}
	while(n and n % 5 == 0) {
		factors[1][x][y]++;
		n /= 5;
	}
}

int solve(int i, int x, int y) {
	if(grid[x][y] == 0) {
		return oo;
	} else if(x == n and y == n) {
		return factors[i][x][y];
	} else if(~dp[i][x][y]) {
		return dp[i][x][y];
	}
	return dp[i][x][y] = min(solve(i, x + 1, y), solve(i, x, y + 1)) + factors[i][x][y];
}

int main(void) {
	scanf("%d", &n);
	memset(dp, -1, sizeof dp);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			scanf("%d", &grid[i][j]);
			compute_factors(i, j);
		}
	}
	int x = solve(0, 1, 1), y = solve(1, 1, 1);
	printf("%d\n", min(x, y));
	return 0;
}
