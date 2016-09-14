#include <bits/stdc++.h>

#define MAX 10005

using namespace std;

vector<int> graph[MAX];
bool visited[MAX];
int visiteds;

void dfs(int u) {
	visited[u] = true;

	for(auto& v : graph[u]) {
		if(not visited[v])
			dfs(v);
	}

	++visiteds;
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);

		for(int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
		}

		visiteds = 0;
		memset(visited, false, sizeof visited);
		for(int i = 0; i < k; ++i) {
			int u;
			scanf("%d", &u);
			if(not visited[u])
				dfs(u);
		}

		printf("%d\n", visiteds);

		for(int u = 1; u <= n; ++u)
			graph[u].clear();
	}

	return 0;
}
