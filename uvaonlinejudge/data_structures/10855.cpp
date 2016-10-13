#include <bits/stdc++.h>

#define MAX 1024

char grid[MAX][MAX], sub_grid[MAX][MAX];

int main(void) {
	int n, m;
	while(scanf("%d %d", &n, &m), (n | m)) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				scanf(" %c", &grid[i][j]);
			}
		}

		for(int i = 1; i <= m; ++i) {
			for(int j = 1; j <= m; ++j) {
				scanf(" %c", &sub_grid[i][j]);
			}
		}


		int rotate_0, rotate_90, rotate_180, rotate_270;
		rotate_0 = rotate_90 = rotate_180 = rotate_270 = 0;
		for(int i = 1; (i + m - 1) <= n; ++i) {
			for(int j = 1; (j + m - 1) <= n; ++j) {
				int count;

				count = 0;
				for(int u = i, x = 1; x <= m; ++u, ++x) {
					for(int v = j, y = 1; y <= m; ++v, ++y) {
						if(grid[u][v] == sub_grid[x][y]) {
							++count;							
						}
					}
				}

				if(count == (m * m))
					++rotate_0;

				count = 0;
				for(int u = i, y = m; y >= 1; ++u, --y) {
					for(int v = j, x = 1; x <= m; ++v, ++x) {
						if(grid[u][v] == sub_grid[x][y]) {
							++count;							
						}
					}
				}

				if(count == (m * m))
					++rotate_90;

				count = 0;
				for(int u = i, x = m; x >= 1; ++u, --x) {
					for(int v = j, y = m; y >= 1; ++v, --y) {
						if(grid[u][v] == sub_grid[x][y]) {
							++count;							
						}
					}
				}

				if(count == (m * m))
					++rotate_180;

				count = 0;
				for(int u = i, y = 1; y <= m; ++u, ++y) {
					for(int v = j, x = m; x >= 1; ++v, --x) {
						if(grid[u][v] == sub_grid[x][y]) {
							++count;							
						}
					}
				}

				if(count == (m * m))
					++rotate_270;
			}
		}

		printf("%d %d %d %d\n", rotate_0, rotate_270, rotate_180, rotate_90);
	}

	return 0;
}
