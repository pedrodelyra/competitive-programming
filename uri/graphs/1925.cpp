#include <bits/stdc++.h>

#define MAX 1024

using namespace std;
using ii = pair<int, int>;

char grid[MAX][MAX];
int n, m, colors[MAX][MAX], flood_fill[MAX * MAX], visiteds;
vector<ii> movements = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}, sources;

void dfs(int x, int y, int color) {
	colors[x][y] = color;
	for(auto& move : movements) {
		int dx = move.first, dy = move.second;
		if(grid[x + dx][y + dy] == 'n' && not colors[x + dx][y + dy]) {
			dfs(x + dx, y + dy, color);
		}
	}
	++visiteds;
}

int main(void) {
	int max_visiteds = 0, color = 0;
	scanf("%d %d", &n, &m);
	memset(grid, -1, sizeof grid);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			char c;
			scanf(" %c", &grid[i][j]);

			if(grid[i][j] == '*') sources.push_back(ii(i, j));
		}
	}

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(grid[i][j] == 'n' && not colors[i][j]) {
				visiteds = 0;
				dfs(i, j, ++color);
				flood_fill[color] = visiteds;
			}
		}
	}

	ii ans;
	for(auto& source : sources) {
		int x = source.first, y = source.second;
		set<int> adj_colors;
		for(auto& move : movements) {
			int dx = move.first, dy = move.second;
			if(grid[x + dx][y + dy] == 'n') adj_colors.insert(colors[x + dx][y + dy]);
		}

		int vis = 0;
		for(auto& c : adj_colors) {
			vis += flood_fill[c];
		}

		if(max_visiteds < vis) {
			ans = ii(x, y);
			max_visiteds = vis;
		}
	}

	printf("%d,%d\n", ans.first, ans.second);

	return 0;
}
