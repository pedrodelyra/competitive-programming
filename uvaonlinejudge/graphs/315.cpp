#include <bits/stdc++.h>

#define MAX 128

using namespace std;

vector<int> graph[MAX];
int dfs_num[MAX], dfs_low[MAX], parents[MAX], dfs_counter, root, root_children;
bool art_point[MAX];

void tarjan(int u) {
	dfs_num[u] = dfs_low[u] = ++dfs_counter;
	for(auto& v : graph[u]) {
		if(not dfs_num[v]) {
			parents[v] = u;

			tarjan(v);

			if(u == root) ++root_children;

			if(dfs_low[v] >= dfs_num[u]) art_point[u] = true;

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		} else if(parents[u] != v) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main(void) {
	int n;
	while(scanf("%d\n", &n), n) {
		string adj_list;
		while(getline(cin, adj_list), adj_list[0] != '0') {
			stringstream ss(adj_list);

			int u, v;
			ss >> u;
			while(ss >> v) {
				graph[u].push_back(v);
				graph[v].push_back(u);
			}
		}

		memset(dfs_num, 0, sizeof dfs_num);
		memset(dfs_low, 0, sizeof dfs_low);
		memset(parents, 0, sizeof parents);
		memset(art_point, false, sizeof art_point);
		dfs_counter = 0;
		for(int u = 1; u <= n; ++u) {
			if(not dfs_num[u]) {
				root = u, root_children = 0;
				tarjan(u);
				art_point[root] = root_children > 1;
			}
		}

		int sol = 0;
		for(int u = 1; u <= n; ++u) {
			sol += art_point[u];
		}

		printf("%d\n", sol);

		for(int u = 1; u <= n; ++u)
			graph[u].clear();
	}

	return 0;
}
