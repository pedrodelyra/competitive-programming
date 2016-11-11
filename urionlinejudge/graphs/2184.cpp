#include <bits/stdc++.h>

#define MAX	   200005
#define LOGMAX	   30
#define MAX_ROUTES 5005
#define MAX_POINTS 2005
#define oo         5000005

using namespace std;
using ii = pair<int, int>;

vector<ii> tree[MAX], routes(MAX_ROUTES);

int n, m, k, dp[MAX_ROUTES][MAX_POINTS], visited[MAX], p[MAX], pw[MAX], level[MAX], A[MAX][LOGMAX], g[MAX][LOGMAX];

void dfs(int u, int h) {
	visited[u] = true;
	level[u] = h;
	for(auto& edge : tree[u]) {
		int w = edge.first, v = edge.second;
		if(not visited[v]) {
			p[v] = u, pw[v] = w;
			dfs(v, h + 1);
		}
	}
}

void preprocess(int n) {
	memset(A, -1, sizeof A);
	memset(g, -1, sizeof g);
	for(int i = 1; i <= n; ++i) {
		A[i][0] = p[i];
		g[i][0] = pw[i];
	}
	for(int j = 1; 1 << j <= n; ++j) {
		for(int i = 1; i <= n; ++i) {
			if(~A[i][j - 1]) {
				A[i][j] = A[A[i][j - 1]][j - 1];
				g[i][j] = max(g[i][j - 1], g[A[i][j - 1]][j - 1]);
			}
		}
	}
}

ii query(int u, int v) {
	if(level[u] < level[v]) swap(u, v);

	int lg, ans = -oo, a = u, b = v;
	for(lg = 1; 1 << lg <= level[u]; ++lg);
	lg--;

	for(int i = lg; i >= 0; --i) {
		if(level[u] - (1 << i) >= level[v]) {
			ans = max(ans, max(pw[u], g[u][i]));
			u = A[u][i];
		}
	}

	if(u == v) {
		return ii(ans, level[a] - level[b] + 1);
	} else {
		for(int i = lg; i >= 0; --i) {
			if(~A[u][i] and A[u][i] != A[v][i]) {
				ans = max(ans, max(max(pw[u], pw[v]), max(g[u][i], g[v][i])));
				u = A[u][i];
				v = A[v][i];
			}
		}
		return ii(max(ans, max(pw[u], pw[v])), level[a] + level[b] - 2 * level[p[u]] + 1);
	}
}

int solve(int i, int sum) {
	if(sum > m) {
		return -oo;
	} else if(i > k) {
		return 0;
	} else if(~dp[i][sum]) {
		return dp[i][sum];
	}
	return dp[i][sum] = max(solve(i + 1, sum), solve(i + 1, sum + routes[i].second) + routes[i].first);
}

int main(void) {
	const int root = 1;
	scanf("%d %d", &n, &m);
	for(int i = 1; i < n; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		tree[u].push_back(ii(w, v));
		tree[v].push_back(ii(w, u));
	}
	p[root] = root, pw[root] = -oo, dfs(root, 0);
	preprocess(n);
	scanf("%d", &k);
	for(int i = 1; i <= k; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		routes[i] = query(u, v);
	}
	memset(dp, -1, sizeof dp);
	int ans = solve(1, 0);
	printf("%d\n", ans > 0 ? ans : -1);
	return 0;
}
