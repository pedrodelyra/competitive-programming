#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;
using ii = pair<int, int>;

int n, m, k, t, horse, graph[20][20], dist[105][105], pawn_id[105][105], dp[16][1 << 16];
char grid[105][105];
ii pawns[20];

void bfs(ii source) {
	int x0 = source.first, y0 = source.second;
	memset(dist, -1, sizeof dist);
	dist[x0][y0] = 0;

	queue<ii> q;
	q.push(source);
	while(not q.empty()) {
		ii u = q.front();
		q.pop();
		int x = u.first, y = u.second;
		if(~pawn_id[x][y]) graph[pawn_id[source.first][source.second]][pawn_id[x][y]] = dist[x][y];
		for(int dx = -2; dx <= 2; ++dx) {
			for(int dy = -2; dy <= 2; ++dy) { 
				if(abs(dx) + abs(dy) == 3) {
					if(grid[x + dx][y + dy] == '.' && !~dist[x + dx][y + dy]) {
						dist[x + dx][y + dy] = dist[x][y] + 1;
						q.push(ii(x + dx, y + dy));
					}
				}
			}
		}
	}
}

int tsp(int u, int mask) {
	if(mask == ((1 << t) - 1)) {
		return graph[u][horse];
	} else if(~dp[u][mask]) {
		return dp[u][mask];
	}

	int min_dist = INF;
	for(int i = 0; i < t; ++i) {
		if((mask >> i) & 1) continue;
		min_dist = min(min_dist, tsp(i, (mask | (1 << i))) + graph[u][i]);
	}

	return dp[u][mask] = min_dist;
}

int main(void) {
	while(scanf("%d %d %d", &n, &m, &k), (n | m | k)) {
		t = 0;
		memset(grid, '#', sizeof grid);
		memset(pawn_id, -1, sizeof pawn_id);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				scanf(" %c", &grid[i][j]);
				if(grid[i][j] == 'P' || grid[i][j] == 'C') {
					if(grid[i][j] == 'C') horse = t;

					grid[i][j] = '.';
					pawns[pawn_id[i][j] = t++] = ii(i, j);
				}
			}
		}

		for(int i = 0; i < t; ++i) bfs(pawns[i]);

		memset(dp, -1, sizeof dp);
		printf("%d\n", tsp(horse, 1 << horse));
	}

	return 0;
}
