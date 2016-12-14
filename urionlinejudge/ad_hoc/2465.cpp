#include <bits/stdc++.h>

#define MAX 128

using namespace std;
using vii = vector<pair<int, int>>;

int visiteds, visited[MAX][MAX], grid[MAX][MAX];
vii movements = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(int x, int y) {
	visited[x][y] = true;
	for(auto& move : movements) {
		int dx = move.first, dy = move.second;
		if(not visited[x + dx][y + dy] and grid[x + dx][y + dy] >= grid[x][y]) {
			dfs(x + dx, y + dy);
		}
	}
	++visiteds;
}

int main(void) {
	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			scanf("%d", &grid[i][j]);
		}
	}
	dfs(x, y);
	printf("%d\n", visiteds);
	return 0;
}
