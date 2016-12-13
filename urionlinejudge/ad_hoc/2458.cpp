#include <bits/stdc++.h>

#define MAX     512
#define unsafe -1

using move = std::map<char, std::pair<int, int>>;

char grid[MAX][MAX];
bool unsafe_path, visited[MAX][MAX];
move moves {{'A', {-1, 0}}, {'>', {0, 1}}, {'V', {1, 0}}, {'<', {0, -1}}};

void dfs(int x, int y) {
	visited[x][y] = true;
	int dx = moves[grid[x][y]].first, dy = moves[grid[x][y]].second;
	if(grid[x + dx][y + dy] == unsafe) {
		unsafe_path = true;
	} else if(not visited[x + dx][y + dy]) {
		dfs(x + dx, y + dy);
	}
	if(unsafe_path) grid[x][y] = unsafe;
}

int main(void) {
	int n;
	scanf("%d", &n);
	memset(grid, unsafe, sizeof grid);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			scanf(" %c", &grid[i][j]);
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(not visited[i][j]) {
				unsafe_path = false, dfs(i, j);
			}
		}
	}
	int safe_cells = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(grid[i][j] != unsafe) {
				++safe_cells;
			}
		}
	}
	printf("%d\n", safe_cells);
	return 0;
}
