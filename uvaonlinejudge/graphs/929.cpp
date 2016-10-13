#include <bits/stdc++.h>

#define MAX 1024
#define INF -1

using namespace std;
using ii = pair<int, int>;
using iii = pair<int, ii>;

unsigned grid[MAX][MAX];
unsigned dist[MAX][MAX];

unsigned dijkstra(void) {
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	memset(dist, INF, sizeof dist);
	dist[1][1] = grid[1][1];
	pq.push(iii(dist[1][1], ii(1, 1)));
	while(not pq.empty()) {
		auto current = pq.top();
		pq.pop();

		int x = current.second.first, y = current.second.second, current_dist = current.first;

		if(current_dist > dist[x][y]) continue;

		for(int i = -1; i <= 1; i += 2) {
			if(~grid[x + i][y]) {
				if(dist[x + i][y] > dist[x][y] + grid[x + i][y]) {
					dist[x + i][y] = dist[x][y] + grid[x + i][y];
					pq.push(iii(dist[x + i][y], ii(x + i, y)));
				}
			}

			if(~grid[x][y + i]) {
				if(dist[x][y + i] > dist[x][y] + grid[x][y + i]) {
					dist[x][y + i] = dist[x][y] + grid[x][y + i];
					pq.push(iii(dist[x][y + i], ii(x, y + i)));
				}
			}
		}
	}
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n, m;
		scanf("%d %d", &n, &m);
		memset(grid, -1, sizeof grid);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				scanf("%u", &grid[i][j]);
			}
		}

		dijkstra();

		printf("%d\n", dist[n][m]);
	}

	return 0;
}
