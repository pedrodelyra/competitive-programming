#include <bits/stdc++.h>

using namespace std;

int n, m, visiteds;
char grid[32][32], land, water = 0;
bool visited[32][32];

void sink_root_island(int x, int y) {
	visited[x][y] = true;

	for(int i = -1; i <= 1; i += 2) {
		if(x + i >= 0 && x + i < n) {
			if(not visited[x + i][y] && grid[x + i][y] == land)
				sink_root_island(x + i, y);
		}

		if(not visited[x][(m + y + i) % m] && grid[x][(m + y + i) % m] == land)
			sink_root_island(x, (m + y + i) % m);
	}

	grid[x][y] = water;
}

void dfs(int x, int y) {
	visited[x][y] = true;

	for(int i = -1; i <= 1; i += 2) {
		if(x + i >= 0 && x + i < n) {
			if(not visited[x + i][y] && grid[x + i][y] == land) {
				dfs(x + i, y);
			}
		}

		if(not visited[x][(m + y + i) % m] && grid[x][(m + y + i) % m] == land) {
			dfs(x, (m + y + i) % m);
		}
	}

	visiteds++;
}

int main(void) {
	while(scanf("%d %d", &n, &m) != EOF) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				scanf(" %c", &grid[i][j]);
			}
		}

		int x, y, result = 0;
		scanf("%d %d", &x, &y);
		land = grid[x][y];
		memset(visited, false, sizeof visited);
		sink_root_island(x, y);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(not visited[i][j] && grid[i][j] == land) {
					visiteds = 0;
					dfs(i, j);
					result = max(result, visiteds);
				}
			}
		}

		printf("%d\n", result);
	}

	return 0;
}
