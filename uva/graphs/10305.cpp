#include <bits/stdc++.h>

#define MAX 128

using namespace std;

vector<int> graph[MAX];
int in_degree[MAX];

int main(void) {
	int n, m;
	while(scanf("%d %d", &n, &m), (n | m)) {
		memset(in_degree, 0, sizeof in_degree);
		for(int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
			in_degree[v]++;
		}

		queue<int> roots;
		for(int u = 1; u <= n; ++u) {
			if(in_degree[u] == 0) {
				roots.push(u);
			}
		}

		bool flag = true;
		while(not roots.empty()) {
			int u = roots.front();
			roots.pop();

			if(flag) { flag = false; } else { printf(" "); }
			printf("%d", u);

			for(auto& v : graph[u]) {
				in_degree[v]--;
				if(in_degree[v] == 0) {
					roots.push(v);
				}
			}
		}
		printf("\n");

		for(int u = 1; u <= n; ++u)
			graph[u].clear();
	}

	return 0;
}
