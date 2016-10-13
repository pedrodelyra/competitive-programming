#include <bits/stdc++.h>

#define MAX 1024

using namespace std;

vector<int> graph[MAX];
int grid[MAX][MAX], color[MAX];

bool bfs(int source) {
	queue<int> q;
	color[source] = 1;
	q.push(source);
	while(not q.empty()) {
		auto u = q.front();
		for(auto& v : graph[u]) {
			if(!~color[v]) {
				color[v] = !color[u];
				q.push(v);
			} else if(color[u] == color[v]) {
				return false;
			}
		}

		q.pop();
	}

	return true;
}

int main(void) {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			scanf("%d", &grid[i][j]);
			if(grid[i][j] == 0) graph[i].push_back(j);
		}
	}

	bool ans = true;
	memset(color, -1, sizeof color);
	for(int u = 1; u <= n && ans; ++u) {
		if(!~color[u]) {
			ans &= bfs(u);
		}
	}

	printf(ans ? "Bazinga!\n" : "Fail!\n");

	return 0;
}
