#include <bits/stdc++.h>

#define MAX 32
#define INF 0x3f3f3f3f

using namespace std;
using iii = tuple<int, int, int>;

char grid[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];

int bfs(iii source, iii destination) {
	queue<iii> q;
	int x0, y0, z0, xf, yf, zf;
	tie(x0, y0, z0) = source;
	tie(xf, yf, zf) = destination;

	memset(dist, INF, sizeof dist);
	dist[x0][y0][z0] = 0;
	q.push(source);
	while(not q.empty()) {
		auto current_pos = q.front();
		int x, y, z;
		tie(x, y, z) = current_pos;

		if(current_pos == destination) break;

		for(int i = -1; i <= 1; i += 2) {
			if(grid[x + i][y][z] != '#' && dist[x + i][y][z] == INF) {
				dist[x + i][y][z] = dist[x][y][z] + 1;
				q.push(iii(x + i, y, z));
			}

			if(grid[x][y + i][z] != '#' && dist[x][y + i][z] == INF) {
				dist[x][y + i][z] = dist[x][y][z] + 1;
				q.push(iii(x, y + i, z));
			}

			if(grid[x][y][z + i] != '#' && dist[x][y][z + i] == INF) {
				dist[x][y][z + i] = dist[x][y][z] + 1;
				q.push(iii(x, y, z + i));
			}
		}

		q.pop();
	}

	return dist[xf][yf][zf];
}

int main(void) {
	int l, n, m;
	while(scanf("%d %d %d", &l, &n, &m), l | n | m) {
		iii source, destination;
		memset(grid, '#', sizeof grid);
		for(int k = 1; k <= l; ++k) {
			for(int i = 1; i <= n; ++i) {
				for(int j = 1; j <= m; ++j) {
					scanf(" %c", &grid[i][j][k]);

					if(grid[i][j][k] == 'S') source = iii(i, j, k);

					if(grid[i][j][k] == 'E') destination = iii(i, j, k);
				}
			}
		}

		int min_path = bfs(source, destination);
		printf(min_path < INF ? "Escaped in %d minute(s).\n" : "Trapped!\n", min_path);
	}

	return 0;
}
