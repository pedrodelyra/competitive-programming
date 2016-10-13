#include <bits/stdc++.h>

#define MAX 100005

using namespace std;
using ll = long long int;
using ii = pair<ll, int>;

vector<ii> tree[MAX];
int euler_tour[MAX << 1], first_occur[MAX], segtree[MAX << 3], k;
ll dist[MAX];

void bfs(int root) {
	queue<int> q;
	q.push(root);
	dist[root] = 0;
	while(not q.empty()) {
		int u = q.front();
		for(auto& edge : tree[u]) {
			ll w = edge.first; int v = edge.second;
			dist[v] = dist[u] + w;
			q.push(v);
		}
		q.pop();
	}
}

void dfs(int u) {
	euler_tour[k++] = u;
	for(auto& edge : tree[u]) {
		dfs(edge.second);
		euler_tour[k++] = u;
	}
}

void build_segtree(int p = 1, int L = 0, int R = k - 1) {
	if(L == R) {
		segtree[p] = euler_tour[L];
	} else {
		int mid = (L + R) >> 1;
		build_segtree(2 * p, L, mid);
		build_segtree(2 * p + 1, mid + 1, R);

		int u = segtree[2 * p], v = segtree[2 * p + 1];
		if(dist[u] < dist[v]) {
			segtree[p] = u;
		} else {
			segtree[p] = v;
		}
	}
}

int LCA(int i, int j, int p = 1, int L = 0, int R = k - 1) {
	if(i > R || j < L) {
		return -1;
	}

	if(L >= i && R <= j) {
		return segtree[p];
	}

	int mid = (L + R) >> 1;
	int u = LCA(i, j, 2 * p, L, mid), v = LCA(i, j, 2 * p + 1, mid + 1, R);

	if(!~u) return v;

	if(!~v) return u;

	if(dist[u] < dist[v]) {
		return u;
	} else {
		return v;
	}
}

int main(void) {
	int n, root = 0;
	while(scanf("%d", &n), n) {
		for(int u = 1; u < n; ++u) {
			int v, w;
			scanf("%d %d", &v, &w);
			tree[v].push_back(ii(w, u));
		}

		k = 0;
		dfs(root);
		bfs(root);
		build_segtree();

		memset(first_occur, -1, sizeof first_occur);
		for(int i = 0; i < k; ++i) {
			if(!~first_occur[euler_tour[i]]) first_occur[euler_tour[i]] = i;
		}

		int queries;
		scanf("%d", &queries);
		for(int q = 0; q < queries; ++q) {
			int u, v, x, y;
			scanf("%d %d", &u, &v);

			x = min(first_occur[u], first_occur[v]);
			y = max(first_occur[u], first_occur[v]);

			if(q) printf(" ");
			printf("%lld", dist[u] + dist[v] - 2 * dist[LCA(x, y)]);
		}
		printf("\n");

		for(int u = 0; u < n; ++u)
			tree[u].clear();
	}

	return 0;
}
