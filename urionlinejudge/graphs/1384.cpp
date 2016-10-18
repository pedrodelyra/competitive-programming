#include <bits/stdc++.h>

#define MAX 1024
#define oo  0x2f2f2f2f

using namespace std;
using ii    = pair<int, int>;
using state = tuple<int, int, int>;

char grid[MAX][MAX];
int  dist[MAX][MAX], cost[MAX][MAX];

vector<ii>   movements;

void set_frog_movements() {
	for(int i = -2; i <= 2; ++i) {
		for(int j = -2; j <= 2; ++j) {
			if(i || j) movements.push_back(ii(i, j));
		}
	}
}

void set_movements_cost() {
	for(int i = -2; i <= 2; ++i) {
		for(int j = -2; j <= 2; ++j) {
			if(i || j) {
				if(abs(i) + abs(j) == 4) {
					cost[abs(i)][abs(j)] = 7;
				} else if(abs(i) + abs(j) == 3) {
					cost[abs(i)][abs(j)] = 6;
				} else if(abs(i) == 2 || abs(j) == 2) {
					cost[abs(i)][abs(j)] = 5;
				} else if(abs(i) + abs(j) == 2) {
					cost[abs(i)][abs(j)] = 3;
				} else {
					cost[abs(i)][abs(j)] = 2;
				}
			}
		}
	}	
}

int dijkstra(int x0, int y0, int xf, int yf) {
	priority_queue<state, vector<state>, greater<state>> pq;
	memset(dist, oo, sizeof dist);
	pq.push(state(dist[x0][y0] = 0, x0, y0));
	while(not pq.empty()) {
		auto current_state = pq.top(); pq.pop();
		int current_dist, x, y;
		tie(current_dist, x, y) = current_state;

		if(current_dist > dist[x][y]) continue;

		if(x == xf and y == yf) break;

		for(auto& move : movements) {
			int dx = move.first, dy = move.second, w = cost[abs(dx)][abs(dy)];
			if(grid[x + dx][y + dy] and dist[x + dx][y + dy] > dist[x][y] + w) {
				dist[x + dx][y + dy] = dist[x][y] + w;
				pq.push(state(dist[x + dx][y + dy], x + dx, y + dy));
			}
		}
	}
	return dist[xf][yf];
}

int main(void) {
	int n, m;
	set_frog_movements();
	set_movements_cost();
	while(scanf("%d %d", &n, &m), n | m) {
		int x0, y0, xf, yf;
		scanf("%d %d %d %d", &x0, &y0, &xf, &yf);
		int w;
		scanf("%d", &w);
		memset(grid, false, sizeof grid);
		for(int i = 2; i <= n + 1; ++i) {
			for(int j = 2; j <= m + 1; ++j) {
				grid[i][j] = true;
			}
		}

		for(int i = 1; i <= w; ++i) {
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			for(int j = x1 + 1; j <= x2 + 1; ++j) {
				for(int k = y1 + 1; k <= y2 + 1; ++k) {
					grid[j][k] = false;
				}
			}
		}

		int min_dist = dijkstra(x0 + 1, y0 + 1, xf + 1, yf + 1);
		printf(min_dist < oo ? "%d\n" : "impossible\n", min_dist);
	}
	return 0;
}
