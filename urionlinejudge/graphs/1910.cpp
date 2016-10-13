#include <bits/stdc++.h>

#define oo -1
#define MAX 100000

using namespace std;

unsigned dist[MAX + 5], forbidden[MAX + 5];

bool valid(int x) { return 1 <= x && x <= MAX; }

unsigned bfs(int source, int destination) {
	queue<int> q;
	memset(dist, oo, sizeof dist);
	dist[source] = 0;
	q.push(source);
	while(not q.empty()) {
		int u = q.front(), next[5] = {u - 1, u + 1, u & 1 ? oo : u >> 1, u << 1, u * 3};
		for(auto& v : next) {
			if(valid(v)) {
				if(not forbidden[v] and dist[v] == oo) {
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}
		q.pop();
	}

	return dist[destination];
}

int main(void) {
	int u, v, k;
	while(scanf("%d %d %d", &u, &v, &k), u | v | k) {
		memset(forbidden, false, sizeof forbidden);
		for(int i = 1; i <= k; ++i) {
			int x;
			scanf("%d", &x);
			if(valid(x)) {
				forbidden[x] = true;
			}
		}

		printf("%d\n", valid(u) and valid(v) ? bfs(u, v) : oo);
	}

	return 0;
}
