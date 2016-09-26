#include <bits/stdc++.h>

#define MAX 1024
#define oo 0x3f3f3f3f

using namespace std;

vector<int> graph[MAX];
int min_age, node[MAX], age[MAX], visited[MAX];

int dfs(int u) {
	visited[u] = true;
	for(auto& v : graph[u]) {
		if(not visited[v]) {
			dfs(v);
			min_age = min(min_age, age[v]);
		}
	}
}

int main(void) {
	int n, m, k;
	while(~scanf("%d %d %d", &n, &m, &k)) {
		for(int u = 1; u <= n; ++u) {
			scanf("%d", &age[u]);
			node[u] = u;
		}

		for(int i = 1; i <= m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			graph[v].push_back(u);
		}

		while(k--) {
			char cmd;
			scanf(" %c", &cmd);

			if(cmd == 'P') {
				int u;
				scanf("%d", &u);

				min_age = +oo;
				memset(visited, false, sizeof visited);
				dfs(node[u]);
				printf(min_age < +oo ? "%d\n" : "*\n", min_age);
			}

			if(cmd == 'T') {
				int u, v;
				scanf("%d %d", &u, &v);
				swap(age[node[u]], age[node[v]]);
				swap(node[u], node[v]);
			}
		}

		for(int u = 1; u <= n; ++u) {
			graph[u].clear();
		}
	}

	return 0;
}
