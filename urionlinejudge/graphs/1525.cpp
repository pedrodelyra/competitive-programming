#include <bits/stdc++.h>

#define MAX 128
#define oo 0x3f3f3f3f

using namespace std;
using ii = pair<int, int>;
using vii = vector<ii>;
using state = tuple<int, int, int>;

char grid[MAX][MAX];
int n, m, dist[MAX][MAX];
vii movements = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int dijkstra(ii source) {
	int x0, y0, min_cost = oo;
	tie(x0, y0) = source;

	memset(dist, oo, sizeof dist);
	dist[x0][y0] = 0;
	priority_queue<state, vector<state>, greater<state>> pq;
	pq.push(state(dist[x0][y0], x0, y0));
	while(not pq.empty()) {
		auto current_pos = pq.top();
		pq.pop();

		int current_dist, x, y;
		tie(current_dist, x, y) = current_pos;

		if(current_dist > dist[x][y]) continue;

		if(x == 1 || x == n || y == 1 || y == m) min_cost = min(min_cost, dist[x][y]);

		for(auto& move : movements) {
			int dx = move.first, dy = move.second, cost, valid_move;
			cost = (dx == 1 && grid[x + dx][y] == 'v') || (!~dx && grid[x + dx][y] == '^') ||
			       (dy == 1 && grid[x][y + dy] == '>') || (!~dy && grid[x][y + dy] == '<');

			valid_move = (dx && (grid[x + dx][y] == 'v' || grid[x + dx][y] == '^')) ||
				     (dy && (grid[x][y + dy] == '>' || grid[x][y + dy] == '<'));

			if(valid_move && dist[x + dx][y + dy] > dist[x][y] + cost) {
				dist[x + dx][y + dy] = dist[x][y] + cost;
				pq.push(state(dist[x + dx][y + dy], x + dx, y + dy));
			}
		}
	}

	return min_cost;
}

int main(void) {
	int k;
	while(scanf("%d %d %d", &n, &m, &k), n | m | k) {
		ii source((n + 1) >> 1, (m + 1) >> 1);
		memset(grid, 0, sizeof grid);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				scanf(" %c", &grid[i][j]);
			}
		}

		int min_cost = dijkstra(source);
		printf(min_cost <= k ? "Sim\n" : "Nao\n");
	}

	return 0;
}
