#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define MAX 128

using namespace std;

int grid[MAX][MAX], dp[MAX][MAX];

int slide_down(int x, int y) {
	if(~dp[x][y]) {
		return dp[x][y];
	}

	int result = 0;
	for(int i = -1; i <= 1; i += 2) {
		if(grid[x + i][y] < grid[x][y])
			result = max(result, slide_down(x + i, y));

		if(grid[x][y + i] < grid[x][y])
			result = max(result, slide_down(x, y + i));
	}

	return dp[x][y] = result + 1;
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		char name[512];
		int n, m;
		scanf(" %s %d %d", name, &n, &m);
		memset(grid, INF, sizeof grid);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				scanf("%d", &grid[i][j]);
			}
		}

		int ans = 0;
		memset(dp, -1, sizeof dp);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				ans = max(ans, slide_down(i, j));
			}
		}	

		printf("%s: %d\n", name, ans);
	}

	return 0;
}
