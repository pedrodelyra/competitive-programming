#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

vector<ii> movements = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char grid[1024][1024];

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	memset(grid, '.', sizeof grid);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf(" %c", &grid[i][j]);
		}
	}
	int count = 0;
	for(int x = 1; x <= n; ++x) {
		for(int y = 1; y <= m; ++y) {
			if(grid[x][y] == '#') {
				for(auto &move : movements) {
					int dx = move.first, dy = move.second;
					if(grid[x + dx][y + dy] == '.') {
						++count; break;
					}
				}
			}
		}
	}
	printf("%d\n", count);
	return 0;
}
