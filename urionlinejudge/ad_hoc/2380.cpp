#include <bits/stdc++.h>

using namespace std;

class union_find {
private:
	vector<int> parents, rank;

public:
	union_find(int n) : parents(n + 1), rank(n + 1, 0) {
		for(int u = 1; u <= n; ++u) {
			parents[u] = u;
		}
	}

	int find_set(int u) {
		return u == parents[u] ? u : (parents[u] = find_set(parents[u]));
	}

	bool same_set(int u, int v) {
		return find_set(u) == find_set(v);
	}

	void union_set(int u, int v) {
		if(not same_set(u, v)) {
			int x = find_set(u), y = find_set(v);
			if(rank[x] >= rank[y]) {
				parents[y] = parents[x];
			} else {
				parents[x] = parents[y];
			}
			if(rank[x] == rank[y]) ++rank[x];
		}
	}
};

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	union_find ufds(n);
	while(k--) {
		char cmd;
		scanf(" %c", &cmd);
		if(cmd == 'C') {
			int u, v;
			scanf("%d %d", &u, &v);
			printf(ufds.same_set(u, v) ? "S\n" : "N\n");
		}
		if(cmd == 'F') {
			int u, v;
			scanf("%d %d", &u, &v);
			ufds.union_set(u, v);
		}
	}
	return 0;
}
