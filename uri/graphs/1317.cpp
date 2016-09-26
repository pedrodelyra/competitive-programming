#include <bits/stdc++.h>

#define MAX 128

using namespace std;
using ii = pair<int, int>;

vector<int> graph[MAX];
vector<string> msgs[MAX];
int visited[MAX], forwards[MAX][MAX];
ii limits[MAX];

void dfs(int u, int k) {
	visited[u] = true;
	for(auto& v : graph[u]) {
		if(not visited[v]) {
			dfs(v, k);
		}
	}
	forwards[k][u] = graph[u].size();
}

int main(void) {
	int n;
	while(scanf("%d", &n), n) {
		memset(forwards, 0, sizeof forwards);
		for(int u = 1; u <= n; ++u) {
			int v;
			while(scanf("%d", &v), v) {
				graph[u].push_back(v);
			}
		}

		int source, t1, t2, k = 0;
		while(scanf("%d %d %d", &source, &t1, &t2), source) {
			limits[++k] = ii(t1, t2);
			for(int i = 0; i < 3; ++i) {
				char msg[25];
				scanf(" %s", msg);
				msgs[k].push_back(msg);
			}
			memset(visited, false, sizeof visited);
			dfs(source, k);
		}

		for(int u = 1; u <= n; ++u) {
			char name[25];
			scanf(" %s", name);
			printf("%s: ", name);
			for(int i = 1; i <= k; ++i) {
				int t1 = limits[i].first, t2 = limits[i].second, x = forwards[i][u] < t1 ? 0 : (forwards[i][u] < t2 ? 1 : 2);
				printf("%s ", msgs[i][x].c_str());
			}
			printf("\n");
		}

		for(int u = 1; u <= n; ++u) graph[u].clear();
		for(int i = 1; i <= k; ++i) msgs[i].clear();
	}

	return 0;
}
