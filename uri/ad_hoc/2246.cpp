#include <bits/stdc++.h>

#define MAX 256

using namespace std;

int grid[MAX][MAX], visited[MAX][MAX], visiteds;

void dfs(int u, int v, int color) {
	visited[u][v] = true;

	for(int i = -1; i <= 1; i += 2) {
		if(grid[u + i][v] == grid[u][v] && not visited[u + i][v]) {
			dfs(u + i, v, color);
		}

		if(grid[u][v + i] == grid[u][v] && not visited[u][v + i]) {
			dfs(u, v + i, color);
		}
	}

	++visiteds;
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	memset(grid, -1, sizeof grid);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%d", &grid[i][j]);
		}
	}

	int ans = n * m;
	for(int u = 1; u <= n; ++u) {
		for(int v = 1; v <= m; ++v) {
			if(not visited[u][v]) {
				visiteds = 0;
				dfs(u, v, grid[u][v]);
				ans = min(ans, visiteds);
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}
