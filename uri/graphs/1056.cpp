#include <bits/stdc++.h>

#define MAX 256

using namespace std;

vector<int> graph[MAX];
int A[MAX], B[MAX], visited[MAX], match[MAX];

int mcbm(int u) {
	if(visited[u]) return 0;

	visited[u] = true;
	for(auto& v : graph[u]) {
		if(!~match[v] || mcbm(match[v])) {
			match[v] = u;
			return 1;
		}
	}

	return 0;
}

int main(void) {
	int tests;
	scanf("%d", &tests);
	for(int tc = 1; tc <= tests; ++tc) {
		int n, m;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &A[i]);

		scanf("%d", &m);
		for(int i = 0; i < m; ++i)
			scanf("%d", &B[i]);

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if((A[i] && B[j] % A[i] == 0) || B[j] == 0) {
					graph[i].push_back(j + n);
				}
			}
		}

		int ans = 0;
		memset(match, -1, sizeof match);
		for(int i = 0; i < n; ++i) {
			memset(visited, false, sizeof visited);
			ans += mcbm(i);
		}

		printf("Case %d: %d\n", tc, ans);

		for(int i = 0; i <= n + m; ++i)
			graph[i].clear();
	}

	return 0;
}
