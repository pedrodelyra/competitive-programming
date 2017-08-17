#include <bits/stdc++.h>

#define MAX 1024

using namespace std;

vector<int> graph[MAX], colors(MAX);

bool bfs(int source) {
	queue<int> q;
	colors[source] = 0;
	q.push(source);
	while(not q.empty()) {
		auto u = q.front(); q.pop();
                for(auto& v : graph[u]) {
			if(!~colors[v]) {
				colors[v] = 1 - colors[u];
				q.push(v);
			} else if(colors[u] == colors[v]) {
				return false;
			}
		}
	}
	return true;
}

int main(void) {
	int n;
        cin >> n;
	bool is_bipartite = true;
	for(int u = 1; u <= n; ++u) {
		for(int v = 1; v <= n; ++v) {
                        int x; cin >> x;
                        if(x == 0) graph[u].push_back(v);
		}
	}
        fill(begin(colors), end(colors), -1);
	for(int u = 1; u <= n; ++u) {
		if(!~colors[u]) {
			is_bipartite &= bfs(u);
		}
	}
	cout << (is_bipartite ? "Bazinga!" : "Fail!") << endl;
	return 0;
}
