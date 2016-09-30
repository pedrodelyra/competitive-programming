#include <bits/stdc++.h>

#define MAX 128
#define oo 0x3f3f3f3f

using namespace std;

vector<int> graph[MAX];
int dist[MAX];

void bfs(int source) {
	queue<int> q;
	memset(dist, oo, sizeof dist);
	dist[source] = 0;
	q.push(source);
	while(not q.empty()) {
		int u = q.front();
		for(auto& v : graph[u]) {
			if(dist[v] == oo) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
		q.pop();
	}
}

int main(void) {
	int n, m, source, k, tc = 0;
	while(scanf("%d %d %d %d", &n, &m, &source, &k), n | m | source | k) {
		for(int i = 1; i <= m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		bfs(source);
		printf("Teste %d\n", ++tc);
		for(int u = 1; u <= n; ++u) {
			if(u == source) continue;

			if(dist[u] <= k) {
				printf("%d ", u);
			}
		}
		printf("\n\n");
		for(int u = 1; u <= n; ++u) graph[u].clear();	
	}

	return 0;
}
