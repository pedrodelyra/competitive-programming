#include <bits/stdc++.h>

#define MAX 22
#define MAX_T 1024

using namespace std;
using vii = vector<pair<int, int>>;

int max_time, grid[MAX][MAX][MAX_T], dp[MAX][MAX][MAX_T];
vii movements = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool valid_position(int x, int y) {
	return (0 <= x && x <= 20) && (0 <= y && y <= 20);
}

int solve(int x, int y, int t) {
	if(not valid_position(x, y) || t > max_time) {
		return 0;
	} else if(~dp[x][y][t]) {
		return dp[x][y][t];
	}

	int ans = solve(x, y, t + 1);
	for(auto& move : movements) {
		int dx = move.first, dy = move.second;
		ans = max(ans, solve(x + dx, y + dy, t + 1));
	}

	return dp[x][y][t] = ans + grid[x][y][t];
}

int main(void) {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int x, y, t;
		scanf("%d %d %d", &x, &y, &t);
		grid[x][y][t]++;
		max_time = max(max_time, t);
	}

	memset(dp, -1, sizeof dp);
	printf("%d\n", solve(6, 6, 0));
	return 0;
}
