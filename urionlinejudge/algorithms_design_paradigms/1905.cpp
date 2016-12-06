#include <bits/stdc++.h>

using namespace std;
using vii = vector<pair<int, int>>;

int grid[10][10], visited[10][10];
vii movements = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(int x, int y) {
	visited[x][y] = true;
	for(auto& move : movements) {
		int dx = move.first, dy = move.second;
		if(not visited[x + dx][y + dy] and grid[x + dx][y + dy]) {
			dfs(x + dx, y + dy);
		}
	}
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		for(int i = 1; i <= 5; ++i) {
			for(int j = 1; j <= 5; ++j) {
				scanf("%d", &grid[i][j]);
				grid[i][j] = !grid[i][j];
			}
		}
		memset(visited, false, sizeof visited);
		dfs(1, 1);
		printf(visited[5][5] ? "COPS\n" : "ROBBERS\n");
	}
	return 0;
}
