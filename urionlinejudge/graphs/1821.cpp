#include <bits/stdc++.h>

#define MAX 256

using namespace std;

vector<int> graph[MAX];
int match[MAX], visited[MAX], relatives[MAX][MAX];

int mcbm(int u) {
	if(not visited[u]) {
		visited[u] = true;
		for(auto& v : graph[u]) {
			if(!~match[v] || mcbm(match[v])) {
				match[v] = u;
				return 1;
			}
		}
	}
	return 0;
}

int main(void) {
	int n, m, tc = 0;
	while(scanf("%d %d", &n, &m), n | m) {
		int matches = 0;
		memset(relatives, false, sizeof relatives);
		for(int i = 1; i <= m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			relatives[u][v + n] = true;
		}

		for(int i = 1; i <= n; ++i) {
			for(int j = n + 1; j <= (n << 1); ++j) {
				if(not relatives[i][j]) {
					graph[i].push_back(j);
				}
			}
		}

		memset(match, -1, sizeof match);
		for(int u = 1; u <= n; ++u) {
			memset(visited, false, sizeof visited);
			matches += mcbm(u);
		}
		printf(matches == n ? "Instancia %d\npossivel\n\n" : "Instancia %d\nimpossivel\n\n", ++tc);

		for(int u = 1; u <= (n << 1); ++u) graph[u].clear();
	}
	return 0;
}
