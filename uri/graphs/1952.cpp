#include <bits/stdc++.h>

#define MAX 128

using namespace std;
using iii = tuple<int, int, int>;

int n, m, l, grid[MAX][MAX][MAX], dist[MAX][MAX][MAX];

bool is_valid(int x, int y, int z) { return (1 <= x && x <= n) && (1 <= y && y <= m) && (1 <= z && z <= l); }

int bfs(int x1, int y1, int z1, int x2, int y2, int z2) {
	queue<iii> q;
	memset(dist, -1, sizeof dist);
	dist[x1][y1][z1] = 0;
	q.push(iii(x1, y1, z1));
	while(not q.empty()) {
		auto current_pos = q.front();
		int x, y, z;
		tie(x, y, z) = current_pos;

		if(x == x2 && y == y2 && z == z2) break;

		for(int dx = -2; dx <= 2; ++dx) {
			for(int dy = -2; dy <= 2; ++dy) {
				for(int dz = -2; dz <= 2; ++dz) {
					if(abs(dx) + abs(dy) + abs(dz) == 3) {
						if(is_valid(x + dx, y + dy, z + dz) && !~dist[x + dx][y + dy][z + dz]) {
							dist[x + dx][y + dy][z + dz] = dist[x][y][z] + 1;
							q.push(iii(x + dx, y + dy, z + dz));
						}
					}
				}
			}
		}

		q.pop();
	}

	return dist[x2][y2][z2];
}

int main(void) {
	int x1, y1, z1, x2, y2, z2;
	scanf("%d %d %d %d %d %d %d %d %d", &n, &m, &l, &x1, &y1, &z1, &x2, &y2, &z2);
	printf("%d\n", bfs(x1, y1, z1, x2, y2, z2));
	return 0;
}
