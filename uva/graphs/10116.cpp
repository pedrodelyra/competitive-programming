#include <bits/stdc++.h>

#define oo 0x2f2f2f2f

using namespace std;

map<char, int> dx = {{'N', -1}, {'E', 0}, {'S', 1}, {'W',  0}};
map<char, int> dy = {{'N',  0}, {'E', 1}, {'S', 0}, {'W', -1}};

int main(void) {
	int n, m, r, c;
	while(scanf("%d %d %d", &n, &m, &c), r = 1, n | m | c) {
		char grid[15][15];
		memset(grid, -1, sizeof grid);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				scanf(" %c", &grid[i][j]);
			}
		}

		int dist[15][15], loop = 0;
		memset(dist, oo, sizeof dist), dist[r][c] = 1;
		while(~grid[r][c] and !loop) {
			int u = r, v = c;
			r += dx[grid[u][v]];
			c += dy[grid[u][v]];
			if(dist[r][c] == oo) {
				dist[r][c] = dist[u][v] + 1;
			} else {
				loop = dist[u][v] - dist[r][c] + 1;
			}
		}
		printf("%d step(s) ", dist[r][c] - 1);
		printf(!loop ? "to exit\n" : "before a loop of %d step(s)\n", loop);
	}
	return 0;
}
