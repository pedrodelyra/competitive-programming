#include <bits/stdc++.h>

using namespace std;

vector<int> graph[1 << 10];
int visited[1 << 10], match[1 << 10];

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
	int n, m;
	while(~scanf("%d %d", &n, &m)) {
		for(int i = 1; i <= m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
		}
		int ans = 0;
		memset(match, -1, sizeof match);
		for(int u = 1; u <= n; ++u) {
			memset(visited, false, sizeof visited);
			ans += mcbm(u);
		}
		printf("%d\n", n - ans);
		for(int i = 1; i <= n; ++i) {
			graph[i].clear();
		}
	}
	return 0;
}
