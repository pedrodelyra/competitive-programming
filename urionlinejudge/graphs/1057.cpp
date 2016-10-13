#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

char grid[12][12];
vector<vi> movement_orders = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2},
			      {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
vii movements = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int bfs(vii source) {
	queue<vii> q;
	map<vii, int> dist;
	dist[source] = 1;
	q.push(source);
	while(not q.empty()) {
		auto current_state = q.front();
		for(auto& perm : movement_orders) {
			for(auto& move : movements) {
				auto robots = current_state;
				int dx = move.x, dy = move.y;
				for(auto& id : perm) {
					if(grid[robots[id].x + dx][robots[id].y + dy] != '#') {
						robots[id].x += dx;
						robots[id].y += dy;
					}
				}

				if(robots[0] == robots[1]) {
					robots[0] = current_state[0];
					robots[1] = current_state[1];
				} else if(robots[0] == robots[2]) {
					robots[0] = current_state[0];
					robots[2] = current_state[2];
				} else if(robots[1] == robots[2]) {
					robots[1] = current_state[1];
					robots[2] = current_state[2];
				}

				if(dist[robots] == 0 && (robots[0] != robots[1]) && (robots[0] != robots[2]) && (robots[1] != robots[2])) {
					dist[robots] = dist[current_state] + 1;
					int targets_reached = 0;
					for(auto& r : robots) {
						if(grid[r.x][r.y] == 'X') ++targets_reached;
					}

					if(targets_reached == 3) return dist[robots] - 1;

					q.push(robots);
				}
			}
		}
		q.pop();
	}

	return -1;
}

int main(void) {
	int tests;
	scanf("%d", &tests);
	for(int tc = 1; tc <= tests; ++tc) {
		int n;
		scanf("%d", &n);

		vii robots_pos;
		memset(grid, '#', sizeof grid);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				scanf(" %c", &grid[i][j]);

				if(grid[i][j] == 'A' || grid[i][j] == 'B' || grid[i][j] == 'C') robots_pos.push_back(ii(i, j));
			}
		}

		int min_dist = bfs(robots_pos);
		printf(~min_dist ? "Case %d: %d\n" : "Case %d: trapped\n", tc, min_dist);
	}

	return 0;
}
