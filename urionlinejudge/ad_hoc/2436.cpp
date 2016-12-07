#include <bits/stdc++.h>

#define MAX 1024

using namespace std;
using vii = vector<pair<int, int>>;

int i, j, grid[MAX][MAX], visited[MAX][MAX];
vii movements = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(int x, int y) {
	visited[i = x][j = y] = true;
	for(auto& move : movements) {
		int dx = move.first, dy = move.second;
		if(grid[x + dx][y + dy] and not visited[x + dx][y + dy]) {
			dfs(x + dx, y + dy);
		}
	}
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	int x0, y0;
	scanf("%d %d", &x0, &y0);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%d", &grid[i][j]);
		}
	}
	dfs(x0, y0);
	printf("%d %d\n", i, j);
	return 0;
}
