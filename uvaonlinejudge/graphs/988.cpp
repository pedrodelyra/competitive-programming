#include <bits/stdc++.h>

#define MAX 1024

using namespace std;

vector<int> dag[MAX];
int dp[MAX], out_degree[MAX];

int compute_ways(int u) {
	if(out_degree[u] == 0) {
		return 1;
	} else if(~dp[u]) {
		return dp[u];
	}

	int result = 0;
	for(auto& v : dag[u]) {
		result += compute_ways(v);
	}

	return dp[u] = result;
}

int main(void) {
	int n, tc = 0;
	while(scanf("%d", &n) != EOF) {
		memset(out_degree, 0, sizeof out_degree);
		memset(dp, -1, sizeof dp);
		for(int u = 1; u <= n; ++u) {
			int m;
			scanf("%d", &m);
			for(int i = 0; i < m; ++i) {
				int v;
				scanf("%d", &v);
				dag[u].push_back(v + 1);
				out_degree[u]++;
			}
		}

		if(tc++) printf("\n");
		printf("%d\n", compute_ways(1));

		for(int u = 1; u <= n; ++u)
			dag[u].clear();
	}

	return 0;
}
