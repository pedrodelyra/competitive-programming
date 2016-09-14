#include <bits/stdc++.h>

#define MAX 1024

using namespace std;
using edge = pair<int, int>;

vector<int> graph[MAX];
int dfs_num[MAX], dfs_low[MAX], parents[MAX], dfs_counter;
priority_queue<edge, vector<edge>, greater<edge>> bridges;

void tarjan(int u) {
	dfs_num[u] = dfs_low[u] = ++dfs_counter;
	for(auto& v : graph[u]) {
		if(dfs_num[v] == 0) {
			parents[v] = u;
			tarjan(v);

			if(dfs_low[v] > dfs_num[u]) {
				bridges.push(edge(min(u, v), max(u, v)));
			}

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		} else if(parents[u] != v) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; ++i) {
			int u, v, k;
			scanf("%d (%d)", &u, &k);
			while(k--) {
				scanf("%d", &v);
				graph[u].push_back(v);
			}
		}

		memset(dfs_num, 0, sizeof dfs_num);
		memset(dfs_low, 0, sizeof dfs_low);
		memset(parents, 0, sizeof parents);
		dfs_counter = 0;
		for(int u = 0; u < n; ++u) {
			if(dfs_num[u] == 0) {
				tarjan(u);
			}
		}

		printf("%d critical links\n", bridges.size());
		while(not bridges.empty()) {
			auto current_bridge = bridges.top();
			int u = current_bridge.first, v = current_bridge.second;
			printf("%d - %d\n", u, v);
			bridges.pop();
		}
		printf("\n");

		for(int u = 0; u < n; ++u)
			graph[u].clear();
	}

	return 0;
}
