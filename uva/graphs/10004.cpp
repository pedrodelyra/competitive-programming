#include <bits/stdc++.h>

#define MAX 1024
#define UNCOLORED -1
#define BLUE 0
#define RED 1

using namespace std;

vector<int> graph[MAX];
unsigned color[MAX];

bool is_bicolorable(int root) {
	queue<int> q;
	memset(color, UNCOLORED, sizeof color); 
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

int main(void) {
	int n, m;
	while(scanf("%d %d", &n, &m), n) {
		int root;
		for(int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
			graph[v].push_back(u);
			root = u;
		}

		printf(is_bicolorable(root) ? "BICOLORABLE.\n" : "NOT BICOLORABLE.\n");

		for(int u = 0; u < n; ++u)
			graph[u].clear();
	}

	return 0;
}
