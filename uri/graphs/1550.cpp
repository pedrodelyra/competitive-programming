#include <bits/stdc++.h>

#define oo 0x3f3f3f3f
#define MAX 9999

using namespace std;

int dist[MAX + 5];

int inv(int x) {
	int n = 0;
	while(x) {
		n = 10 * n + x % 10;
		x /= 10;
	}

	return n;
}

int bfs(int source, int destination) {
	queue<int> q;
	memset(dist, oo, sizeof dist);
	dist[source] = 0;
	q.push(source);
	while(not q.empty()) {
		int u = q.front(), next[2] = {u + 1, inv(u)};
		for(auto& v : next) {
			if(v <= MAX && dist[v] == oo) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
		q.pop();
	}

	return dist[destination];
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", bfs(x, y));
	}

	return 0;
}
