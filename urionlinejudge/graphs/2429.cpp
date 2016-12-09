#include <bits/stdc++.h>

#define MAX 20005

using namespace std;

vector<int> original_graph[MAX], reversed_graph[MAX];
bool visited[MAX];

void dfs(int u, vector<int> (&graph)[MAX], stack<int>* s) {
	visited[u] = true;
	for(auto& v : graph[u]) {
		if(not visited[v]) {
			dfs(v, graph, s);
		}
	}
	if(s) s->push(u);
}

int main(void) {
	int n, scc = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		original_graph[u].push_back(v);
		reversed_graph[v].push_back(u);
	}
	stack<int> s;
	for(int u = 1; u <= n; ++u) {
		if(not visited[u]) {
			dfs(u, original_graph, &s);
		}
	}
	memset(visited, false, sizeof visited);
	while(not s.empty() and scc <= 1) {
		int u = s.top(); s.pop();
		if(not visited[u]) {
			dfs(u, reversed_graph, nullptr);
			++scc;
		}
	}
	printf(scc == 1 ? "S\n" : "N\n");
	return 0;
}
