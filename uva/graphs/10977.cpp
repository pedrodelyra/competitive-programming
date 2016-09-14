#include <bits/stdc++.h>

#define MAX 256
#define INF (1 << 30)
#define UNVISITED -1

using namespace std;
using ii = pair<int, int>;

int n, m, dist[MAX][MAX];
bool forbidden_vertices[MAX][MAX];

bool valid_pos(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

void forbid_vertices(int x0, int y0, int range) {
	for(int x = 1; x <= n; ++x) {
		for(int y = 1; y <= m; ++y) {
			if((x - x0) * (x - x0) + (y - y0) * (y - y0) <= range * range)
				forbidden_vertices[x][y] = true;
		}
	}
}

int bfs(void) {
	queue<ii> q;
	memset(dist, UNVISITED, sizeof dist);
	dist[1][1] = 0;
	q.push(ii(1, 1));
	while(not q.empty()) {
		auto current_pos = q.front();
		int x = current_pos.first, y = current_pos.second;

		for(int i = -1; i <= 1; i += 2) {
			if(not forbidden_vertices[x + i][y]) {
				if(valid_pos(x + i, y) && dist[x + i][y] == UNVISITED) {
					dist[x + i][y] = dist[x][y] + 1;
					q.push(ii(x + i, y));
				}
			}

			if(not forbidden_vertices[x][y + i]) {
				if(valid_pos(x, y + i) && dist[x][y + i] == UNVISITED) {
					dist[x][y + i] = dist[x][y] + 1;
					q.push(ii(x, y + i));
				}
			}
		}

		q.pop();
	}

	return dist[n][m] == UNVISITED ? INF : dist[n][m];
}

int main(void) {
	while(scanf("%d %d", &n, &m), (n | m)) {
		int k;
		scanf("%d", &k);
		memset(forbidden_vertices, false, sizeof forbidden_vertices);
		for(int i = 0; i < k; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			forbidden_vertices[x][y] = true;
		}

		scanf("%d", &k);
		while(k--) {
			int x, y, range;
			scanf("%d %d %d", &x, &y, &range);
			forbid_vertices(x, y, range);
		}

		int min_path = bfs();
		printf(min_path < INF ? "%d\n" : "Impossible.\n", min_path);
	}
}
