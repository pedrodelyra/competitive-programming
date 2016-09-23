#include <bits/stdc++.h>

#define MAX 50005

using namespace std;
using ii = pair<int, int>;

vector<int> tree[MAX];
int t, level[MAX], euler_tour[MAX << 1], st[MAX << 2], first_occur[MAX];

void dfs(int u, int dist) {
	first_occur[euler_tour[t] = u] = t++;
	level[u] = dist;
	for(auto& v : tree[u]) {
		if(level[v] == 0) {
			dfs(v, dist + 1);
			euler_tour[t++] = u;
		}
	}
}

void build_segtree(int p = 1, int L = 0, int R = t - 1) {
	if(L == R) {
		st[p] = euler_tour[L];
	} else {
		int mid = (L + R) >> 1;
		build_segtree(p << 1, L, mid);
		build_segtree(p << 1 | 1, mid + 1, R);

		int u = st[p << 1], v = st[p << 1 | 1];
		st[p] = level[u] < level[v] ? u : v;
	}
}

int LCA(int i, int j, int p = 1, int L = 0, int R = t - 1) {
	if(i > R || j < L) return -1;

	if(L >= i && R <= j) return st[p];

	int mid = (L + R) >> 1;
	int u = LCA(i, j, p << 1, L, mid), v = LCA(i, j, p << 1 | 1, mid + 1, R);

	if(!~u) return v;
	if(!~v) return u;

	return level[u] < level[v] ? u : v;
}

int main(void) {
	int n, root = 1;
	scanf("%d", &n);

	map<int, ii> positions;
	for(int i = 1; i <= n; ++i) {
		int u;
		scanf("%d", &u);
		if(positions[u].first == 0) {
			positions[u].first = i;
		} else {
			positions[u].second = i;
		}
	}

	for(int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(root, 1);
	build_segtree();

	int ans = 0;
	for(auto& pos : positions) {
		int u = pos.second.first, v = pos.second.second;
		int x = first_occur[u], y = first_occur[v];
		if(x > y) swap(x, y);
		ans += level[u] + level[v] - 2 * level[LCA(x, y)];
	}
	printf("%d\n", ans);

	return 0;
}
