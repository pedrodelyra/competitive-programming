#include <bits/stdc++.h>

using namespace std;
using ii  = pair<int, int>;
using vvi = vector<vector<int>>;

int n, m, visited[9][9], pass = 1;
map<vvi, int> dist;
vector<ii> movements = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool is_solution(vvi& grid) {
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(grid[i][j] != grid[1][1]) return false;
		}
	}
	return true;
}

void flood_fill(vvi& grid, int x, int y, int alpha, int beta) {
	visited[x][y] = pass;
	for(auto& move : movements) {
		int dx = move.first, dy = move.second;
		if(visited[x + dx][y + dy] != pass and (grid[x + dx][y + dy] == alpha || grid[x + dx][y + dy] == beta)) {
			flood_fill(grid, x + dx, y + dy, alpha, beta);
		}
	}
	grid[x][y] = alpha;
}

int bfs(vvi source) {
	queue<vvi> q;
	dist[source] = 1;
	q.push(source);
	while(not q.empty()) {
		auto current_grid = q.front();
		if(is_solution(current_grid)) {
			return dist[current_grid] - 1;
		} else {
			auto current_dist = dist[current_grid];
			int frequences[10] = {0};
			for(int i = 1; i <= n; ++i) {
				for(int j = 1; j <= m; ++j) {
					if(frequences[current_grid[i][j]] == 0) {
						auto bkp = current_grid;
						flood_fill(current_grid, 1, 1, current_grid[i][j], current_grid[1][1]);
						pass++, frequences[current_grid[i][j]]++;
						if(dist[current_grid] == 0) {
							dist[current_grid] = current_dist + 1;
							q.push(current_grid);
						}
						current_grid = bkp;
					}
				}
			}
		}
		q.pop();
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	vvi source(n + 2);
	for(int i = 1; i <= n; ++i) {
		source[i] = vector<int>(m + 2, -1);
		for(int j = 1; j <= m; ++j) {
			scanf("%1d", &source[i][j]);
		}
	}
	source[0] = source[n + 1] = vector<int>(m + 2, -1);
	printf("%d\n", bfs(source));
	return 0;
}
