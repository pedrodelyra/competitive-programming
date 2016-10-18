#include <bits/stdc++.h>

#define MAX 128
#define oo  -1

using namespace std;
using ii = pair<int, int>;

char grid[MAX][MAX];
unsigned dist[MAX][MAX];
vector<ii> movements = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool is_upper(char c) { return 'A' <= c and c <= 'Z'; }

char char_id(char c) { return toupper(c) - 'A'; }

unsigned bfs(int n, int mask) {
	queue<ii> q;
	memset(dist, oo, sizeof dist);
	dist[1][1] = 1, q.push(ii(1, 1));
	while(not q.empty()) {
		auto current_pos = q.front();
		auto x = current_pos.first, y = current_pos.second;
		for(auto& move : movements) {
			auto dx = move.first, dy = move.second;
			if(is_upper(grid[x + dx][y + dy]) ^ ((mask >> char_id(grid[x + dx][y + dy])) & 1)) {
				if(grid[x + dx][y + dy] and dist[x + dx][y + dy] == oo) {
					dist[x + dx][y + dy] = dist[x][y] + 1;
					if(x + dx == n and y + dy == n) {
						return dist[x + dx][y + dy];
					} else {
						q.push(ii(x + dx, y + dy));
					}
				}
			}
		}
		q.pop();
	}
	return oo;
}

int main(void) {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			scanf(" %c", &grid[i][j]);
		}
	}

	unsigned min_dist = oo;
	for(int mask = 0; mask < (1 << 10); ++mask) {
		if(is_upper(grid[1][1]) ^ ((mask >> char_id(grid[1][1])) & 1)) {
			min_dist = min(min_dist, bfs(n, mask));
		}
	}
	printf("%d\n", min_dist);
	return 0;
}
