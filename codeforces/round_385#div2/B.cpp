#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	char grid[n + 1][m + 1];
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf(" %c", &grid[i][j]);
		}
	}
	int min_x = n, max_x = 1, min_y = m, max_y = 1, cells = 0;
	for(int x = 1; x <= n; ++x) {
		for(int y = 1; y <= m; ++y) {
			if(grid[x][y] == 'X') {
				min_x = min(min_x, x), max_x = max(max_x, x);
				min_y = min(min_y, y), max_y = max(max_y, y);
				++cells;
			}
		}
	}
	printf((max_x - min_x + 1) * (max_y - min_y + 1) == cells ? "YES\n" : "NO\n");
	return 0;
}
