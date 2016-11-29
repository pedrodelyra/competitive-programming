#include <bits/stdc++.h>

#define MAX 128

using namespace std;
using ii = pair<int, int>;

char grid[MAX][MAX];
int  colors[MAX][MAX];
vector<ii> movements = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(int x, int y, int k) {
	colors[x][y] = k;
	for(auto& move : movements) {
		int dx = move.first, dy = move.second;
		if(grid[x + dx][y + dy] == '#' and colors[x + dx][y + dy] == 0) {
			dfs(x + dx, y + dy, k);
		}
	}
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf(" %c", &grid[i][j]);
		}
	}
	int ships = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(grid[i][j] == '#' and colors[i][j] == 0) {
				dfs(i, j, ++ships);
			}
		}
	}
	int k;
	scanf("%d", &k);
	while(k--) {
		int x, y;
		scanf("%d %d", &x, &y);
		grid[x][y] = '.';
	}
	set<int> remaining_ships;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(grid[i][j] == '#') {
				remaining_ships.insert(colors[i][j]);
			}
		}
	}
	printf("%d\n", ships - remaining_ships.size());
	return 0;
}
