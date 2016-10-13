#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

int grid[1024][1024];
int dist[1024][1024];

int bfs(int x0, int y0, int xf, int yf) {
	queue<ii> q;
	memset(dist, -1, sizeof dist);
	dist[x0][y0] = 0;
	q.push(ii(x0, y0));

	while(not q.empty()) {
		ii current = q.front();
		q.pop();

		int x = current.first, y = current.second;

		for(int i = -1; i <= 1; i += 2) {
			if(grid[x + i][y] && dist[x + i][y] == -1) {
				dist[x + i][y] = dist[x][y] + 1;		
				q.push(ii(x + i, y));
			}

			if(grid[x][y + i] && dist[x][y + i] == -1) {
				dist[x][y + i] = dist[x][y] + 1;		
				q.push(ii(x, y + i));
			}
		}
	}

	return dist[xf][yf];
}

int main(void) {
	int n, m;
	while(scanf("%d %d", &n, &m), (n | m)) {
		memset(grid, 0, sizeof grid);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				grid[i][j] = 1;

		int rows;
		scanf("%d", &rows);
		while(rows--) {
			int row, columns;
			scanf("%d %d", &row, &columns);
			while(columns--) {
				int column;
				scanf("%d", &column);
				grid[row + 1][column + 1] = 0;
			}
		}

		int x0, y0, x, y;
		scanf("%d %d", &x0, &y0);
		scanf("%d %d", &x, &y);

		printf("%d\n", bfs(x0 + 1, y0 + 1, x + 1, y + 1));
	}

	return 0;
}
