#include <bits/stdc++.h>

#define MAX 100005

using namespace std;
using ll = long long int;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

vii tree[MAX];
vi euler_tour;
ll dist[MAX], segtree[MAX << 3]; 

void dfs(int u, ll current_dist) {
	euler_tour.push_back(u);
	dist[u] = current_dist;
	for(auto& edge : tree[u]) {
		int v = edge.second, w = edge.first;
		dfs(v, dist[u] + w);
		euler_tour.push_back(u);
	}
}

void build_segtree(int p, int L, int R) {
	if(L == R) {
		segtree[p] = euler_tour[L];
	} else {
		int mid = (L + R) >> 1;
		build_segtree(2 * p, L, mid);
		build_segtree(2 * p + 1, mid + 1, R);

		int u = segtree[2 * p], v = segtree[2 * p + 1];
		segtree[p] = dist[u] < dist[v] ? u : v;
	}
}

int LCA(int i, int j, int p, int L, int R) {
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

	return dist[u] < dist[v] ? u : v;
}

int main(void) {
	int n;
	while(scanf("%d", &n), n) {
		const int root = 0;
		for(int v = 1; v < n; ++v) {
			int u, w;
			scanf("%d %d", &u, &w);
			tree[u].push_back(ii(w, v));
		}

		dfs(root, 0);
		build_segtree(1, 0, euler_tour.size());
		vi first_occur(n, -1);
		for(int i = 0; i < euler_tour.size(); ++i) {
			if(!~first_occur[euler_tour[i]]) first_occur[euler_tour[i]] = i;			
		}

		int queries;
		scanf("%d", &queries);
		for(int q = 0; q < queries; ++q) {
			int u, v;
			scanf("%d %d", &u, &v);

			int x = min(first_occur[u], first_occur[v]), y = max(first_occur[u], first_occur[v]), lca = LCA(x, y, 1, 0, euler_tour.size());

			if(q) printf(" ");
			printf("%lld", dist[u] + dist[v] - 2 * dist[lca]);
		}
		printf("\n");

		for(int u = 0; u < n; ++u) tree[u].clear();	

		euler_tour.clear();
	}

	return 0;
}
