#include <bits/stdc++.h>

#define MAX        1024
#define UNCOLORED -1
#define UNVISITED  0
#define VISITED    1
#define EXPLORED   2

using namespace std;
using ii = pair<int, bool>;

vector<ii> graph[MAX];
int consistency, true_sentences, visiteds, color[MAX], state[MAX];

void dfs(int u, vector<int>& s) {
	state[u] = VISITED;
	for(auto& edge : graph[u]) {
		int v = edge.first;
		if(state[v] == UNVISITED) {
			dfs(v, s);
		} else if(state[v] == VISITED) {
			s.push_back(v);
		}
	}
	state[u] = EXPLORED;
}

void dfs(int u, int x) {
	true_sentences += x;
	for(auto& edge : graph[u]) {
		auto v = edge.first;
		bool t = edge.second == color[u];
		if(!~color[v]) {
			dfs(v, color[v] = t);
		} else if(color[v] != t) {
			consistency = false;
		}
	}
	visiteds++;
}

int main(void) {
	int n;
	while(scanf("%d\n", &n), n) {
		int ans = 0;
		memset(state, UNVISITED, sizeof state);
		memset(color, UNCOLORED, sizeof color);
		for(int u = 1; u <= n; ++u) {
			int v; char veracity[8];
			scanf("Sentence %d is %[^.].\n", &v, veracity);
			graph[v].push_back(ii(u, string(veracity) == "true"));
		}
		vector<int> sources;
		for(int u = 1; u <= n; ++u) {
			if(state[u] == UNVISITED) {
				dfs(u, sources);
			}
		}
		consistency = true;
		for(int i = 0; consistency and i < sources.size(); ++i) {
			int u = sources[i];
			true_sentences = visiteds = 0;
			dfs(u, color[u] = true);
			ans += max(true_sentences, visiteds - true_sentences);
		}
		printf(consistency ? "%d\n" : "Inconsistent\n", ans);
		for(int u = 1; u <= n; ++u) {
			graph[u].clear();
		}
	}
	return 0;
}
