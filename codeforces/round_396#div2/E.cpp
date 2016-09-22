#include <bits/stdc++.h>

#define MAX 300005
#define MOD 1000000007

using namespace std;

vector<int> tree[MAX];
int k, fenwick_x[MAX], fenwick_k[MAX], first_occur[MAX], last_occur[MAX], level[MAX];

void dfs(int u, int dist) {
	first_occur[u] = ++k;
	level[u] = dist;
	for(auto& v : tree[u]) {
		dfs(v, dist + 1);
	}
	last_occur[u] = k;
}

void update(int* fenwick, int idx, int value) {
	while(idx <= k) {
		fenwick[idx] = (fenwick[idx] + value) % MOD;
		while(fenwick[idx] < 0) fenwick[idx] += MOD;
		idx += idx & -idx;
	}
}

int query(int* fenwick, int idx) {
	int sum = 0;
	while(idx) {
		sum = (sum + fenwick[idx]) % MOD;
		while(sum < 0) sum += MOD;
		idx -= idx & -idx;
	}
	return sum;
}

int main(void) {
	int n, root = 1;
	scanf("%d", &n);
	for(int v = 2; v <= n; ++v) {
		int u;
		scanf("%d", &u);
		tree[u].push_back(v);
	}

	dfs(root, 0);

	int q;
	scanf("%d", &q);
	while(q--) {
		int cmd;
		scanf("%d", &cmd);
		if(cmd == 1) {
			int v, x, k;
			scanf("%d %d %d", &v, &x, &k);

			int a = first_occur[v], b = last_occur[v] + 1, value = (x + 1LL * k * level[v]) % MOD;
			update(fenwick_x, a,  value);
			update(fenwick_x, b, -value);
			update(fenwick_k, a,  k);
			update(fenwick_k, b, -k);
		}

		if(cmd == 2) {
			int v;
			scanf("%d", &v);
			int x = query(fenwick_x, first_occur[v]);
			int k = query(fenwick_k, first_occur[v]);
			int ans = (x - 1LL * level[v] * k) % MOD;
			while(ans < 0) ans += MOD;
			printf("%d\n", ans);
		}
	}

	return 0;
}
