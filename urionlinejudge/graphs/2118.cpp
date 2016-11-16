#include <bits/stdc++.h>

#define MAX 100005

using namespace std;
using iii = tuple<int, int, int, int>;

vector<int> graph[MAX];
int colors[MAX];

void bfs(vector<iii>& sources) {
	queue<int> q;
	memset(colors, -1, sizeof colors);
	for(auto& s : sources) {
		int x, y, z, i;
		tie(y, z, x, i) = s;
		if(!~colors[x]) {
			colors[x] = i;
			q.push(x);
		}
	}

	while(not q.empty()) {
		int u = q.front();
		for(auto& v : graph[u]) {
			if(!~colors[v]) {
				colors[v] = colors[u];
				q.push(v);
			}
		}
		q.pop();
	}
}


int main(void) {
	int n, m, s, k;
	scanf("%d %d %d %d", &n, &s, &k, &m);
	vector<iii> sources(s);
	for(int i = 1; i <= s; ++i) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		sources.push_back(iii(y, z, x, i));
	}
	sort(sources.begin(), sources.end(), greater<iii>());
	for(int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	bfs(sources);
	while(k--) {
		int u;
		scanf("%d", &u);
		printf(~colors[u] ? "%d\n" : "Noic\n", colors[u]);
	}
	return 0;
}
