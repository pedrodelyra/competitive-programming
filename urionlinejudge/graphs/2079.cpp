#include <bits/stdc++.h>

#define MAX 6005

using namespace std;

vector<int> tree[MAX];
int visited[MAX], dp[MAX][2];

int solve(int u, bool has_base) {
	if(visited[u]) {
		return 0;
	} else if(~dp[u][has_base]) {
		return dp[u][has_base];
	}
	int ans = 0;
	visited[u] = true;
	for(auto& v : tree[u]) {
		if(has_base) {
			ans += solve(v, false);
		} else {
			ans += max(solve(v, false), solve(v, true));
		}
	}
	visited[u] = false;
	return dp[u][has_base] = ans + has_base;
}

int main(void) {
	int tc, root = 1;
	scanf("%d", &tc);
	while(tc--) {
		int n, ans = 0;
		scanf("%d", &n);
		for(int i = 1; i < n; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		memset(dp, -1, sizeof dp);
		printf("%d\n", max(solve(1, 0), solve(1, 1)));
		for(int u = 1; u <= n; ++u) {
			tree[u].clear();
		}
	}
	return 0;
}
