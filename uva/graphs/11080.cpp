#include <bits/stdc++.h>

#define UNCOLORED -1
#define BLUE 0
#define RED 1

using namespace std;

vector<int> graph[205];
unsigned color[205], color_frequence[2];
bool visited[205];

bool compute_min_guards(int root, int n) {
	queue<int> q;
	q.push(root);
	color[root] = BLUE;

	while(not q.empty()) {
		int u = q.front();
		q.pop();
		for(auto& v : graph[u]) {
			if(color[v] == UNCOLORED) {
				color[v] = !color[u];
				q.push(v);
			} else if(color[v] == color[u]) {
				return false;
			}
		}
	}

	return true;
}

void dfs(int u) {
	visited[u] = true;

	for(auto& v : graph[u]) {
		if(not visited[v])
			dfs(v);
	}

	color_frequence[color[u]]++;
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		bool possible = true; // always keep your hope above all
		memset(color, UNCOLORED, sizeof color);
		for(int u = 0; u < n; ++u) {
			if(color[u] == UNCOLORED) {
				possible = compute_min_guards(u, n);

				if(not possible) break;
			}
		}

		int result = 0;
		if(possible) {
			memset(visited, false, sizeof visited);
			for(int u = 0; u < n; ++u) {
				if(not visited[u]) {
					color_frequence[BLUE] = color_frequence[RED] = 0;
					dfs(u);
					if(color_frequence[BLUE] == 0) {
						result += color_frequence[RED];
					} else if(color_frequence[RED] == 0) {
						result += color_frequence[BLUE];
					} else {
						result += min(color_frequence[BLUE], color_frequence[RED]);
					}
				}
			}
		}

		printf("%d\n", possible ? result : -1);

		for(int u = 0; u < n; ++u)
			graph[u].clear();
	}

	return 0;
}
