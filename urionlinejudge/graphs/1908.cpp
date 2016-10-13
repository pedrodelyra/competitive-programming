#include <bits/stdc++.h>

#define MAX 10005
#define oo 0x3f3f3f3f

using namespace std;

vector<int> graph[MAX];
int dist[MAX];

int bfs(int source, int destination) {
	queue<int> q;
	memset(dist, oo, sizeof dist);
	dist[source] = 0;
	q.push(source);
	while(not q.empty()) {
		int u = q.front();

		if(u == destination) break;

		for(auto& v : graph[u]) {
			if(dist[v] == oo) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
		q.pop();
	}

	return dist[destination];
}

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	for(int u = 1; u <= k; ++u) {
		int m;
		scanf("%d", &m);
		vector<int> nodes(m);
		for(int i = 0; i < m; ++i) {
			scanf("%d", &nodes[i]);
		}

		for(int i = 0; i < m; ++i) {
			for(int j = i + 1; j < m; ++j) {
				graph[nodes[i]].push_back(nodes[j]);
				graph[nodes[j]].push_back(nodes[i]);
			}
		}
	}

	printf("%d\n", bfs(1, n));

	return 0;
}
