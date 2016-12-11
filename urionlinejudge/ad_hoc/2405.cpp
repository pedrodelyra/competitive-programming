#include <bits/stdc++.h>

using namespace std;

bool forbidden[256][256], visited[256][256];

void dfs(int x, int y, int& colored_squares) {
	visited[x][y] = true;
	for(int dx = -1; dx <= 1; ++dx) {
		for(int dy = -1; dy <= 1; ++dy) {
			if(not forbidden[x + dx][y + dy] and not visited[x + dx][y + dy]) {
				dfs(x + dx, y + dy, colored_squares);
			}
		}
	}
	colored_squares++;
}

int main(void) {
	int n, m, x0, y0, k;
	scanf("%d %d %d %d %d", &n, &m, &x0, &y0, &k);
	memset(forbidden, true, sizeof forbidden);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			forbidden[i][j] = false;
		}
	}
	int colored_squares = 0;
	for(int i = 1; i <= k; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		forbidden[x][y] = true;
	}
	dfs(x0, y0, colored_squares);
	printf("%d\n", colored_squares);
	return 0;
}
