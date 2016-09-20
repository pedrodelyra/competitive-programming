#include <bits/stdc++.h>

#define MAX 128

using namespace std;
using ii = pair<int, int>;

vector<ii> movements = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int n, m, grid[MAX][MAX], visited[MAX][MAX], match[MAX][MAX];

int mcbm(int x, int y) {
	if(not visited[x][y]) {
		visited[x][y] = true;
		for(auto& move : movements) {
			int dx = move.first, dy = move.second;
			if(~grid[x + dx][y + dy]) {
				if(!~match[x + dx][y + dy] || mcbm(match[x + dx][y + dy] / m + 1, match[x + dx][y + dy] % m + 1)) {
					match[x + dx][y + dy] = m * x + y;
					return 1;
				}
			}
		}
	}

	return 0;
}

int main(void) {
	while(scanf("%d %d", &n, &m), n | m) {
		int k, lake[MAX][MAX] = {false};
		scanf("%d", &k);
		memset(grid, -1, sizeof grid);
		for(int i = 0; i < k; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			lake[x][y] = true;
		}

		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				if(not lake[i][j]) grid[i][j] = 0;
			}
		}

		int ans = 0;
		memset(match, -1, sizeof match);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				if(not lake[i][j]) {
					memset(visited, false, sizeof visited);
					ans += mcbm(i, j);
				}
			}
		}

		printf("%d\n",  (ans + 1) >> 1);
	}

	return 0;
}
