#include <bits/stdc++.h>

using namespace std;
using iv = tuple<int, int, int, int>;

int dist[10][10][10][10], forbidden_state[10][10][10][10];

int bfs(iv source, iv destination) {
	queue<iv> q;
	int s1, s2, s3, s4;
	tie(s1, s2, s3, s4) = source;
	memset(dist, -1, sizeof dist);
	dist[s1][s2][s3][s4] = 0;
	q.push(source);
	while(not q.empty()) {
		auto current_state = q.front();
		int u1, u2, u3, u4;
		tie(u1, u2, u3, u4) = current_state;
		for(int mask = 1 << 3; mask; mask >>= 1) {
			int i = (mask >> 3) & 1, j = (mask >> 2) & 1, k = (mask >> 1) & 1, l = mask & 1;
			if(!~dist[(u1 + i) % 10][(u2 + j) % 10][(u3 + k) % 10][(u4 + l) % 10]) {
				if(not forbidden_state[(u1 + i) % 10][(u2 + j) % 10][(u3 + k) % 10][(u4 + l) % 10]) {
					dist[(u1 + i) % 10][(u2 + j) % 10][(u3 + k) % 10][(u4 + l) % 10] = dist[u1][u2][u3][u4] + 1;
					q.push(iv((u1 + i) % 10, (u2 + j) % 10, (u3 + k) % 10, (u4 + l) % 10));
				}
			}

			if(!~dist[(10 + u1 - i) % 10][(10 + u2 - j) % 10][(10 + u3 - k) % 10][(10 + u4 - l) % 10]) {
				if(not forbidden_state[(10 + u1 - i) % 10][(10 + u2 - j) % 10][(10 + u3 - k) % 10][(10 + u4 - l) % 10]) {
					dist[(10 + u1 - i) % 10][(10 + u2 - j) % 10][(10 + u3 - k) % 10][(10 + u4 - l) % 10] = dist[u1][u2][u3][u4] + 1;
					q.push(iv((10 + u1 - i) % 10, (10 + u2 - j) % 10, (10 + u3 - k) % 10, (10 + u4 - l) % 10));
				}
			}
		}

		q.pop();
	}

	int t1, t2, t3, t4;
	tie(t1, t2, t3, t4) = destination;
	return dist[t1][t2][t3][t4];
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		iv source = iv(a, b, c, d);

		scanf("%d %d %d %d", &a, &b, &c, &d);
		iv destination = iv(a, b, c, d);

		int n;
		scanf("%d", &n);
		memset(forbidden_state, false, sizeof forbidden_state);
		for(int i = 0; i < n; ++i) {
			scanf("%d %d %d %d", &a, &b, &c, &d);
			forbidden_state[a][b][c][d] = true;
		}

		printf("%d\n", bfs(source, destination));
	}

	return 0;
}
