#include <bits/stdc++.h>

#define MAX 2048

using namespace std;

vector<int> graph[MAX];
int visited[MAX], match[MAX];

int dfs(int u) {
	if(not visited[u]) {
		visited[u] = true;
		for(auto& v : graph[u]) {
			if(not match[v] or dfs(match[v])) {
				match[v] = u;
				return 1;
			}
		}
	}
	return 0;
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	char comments[n + 1][255];
	for(int i = 1; i <= n; ++i) {
		scanf(" %[^\n]\n", comments[i]);
		for(int j = 0; comments[i][j]; ++j) {
			comments[i][j] = tolower(comments[i][j]);
		}
	}

	for(int i = 1; i <= m; ++i) {
		char c; int x;
		scanf("%c %d\n", &c, &x);
		for(int j = 1; j <= n; ++j) {
			string s(comments[j]);
			if(count(s.begin(), s.end(), tolower(c)) >= x) {
				graph[j].push_back(i + n);
			}
		}
	}

	int mcbm = 0;
	for(int u = 1; u <= n; ++u) {
		memset(visited, false, sizeof visited);
		mcbm += dfs(u);
	}
	printf("%d\n", mcbm);
	return 0;
}
