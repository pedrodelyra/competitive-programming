#include <bits/stdc++.h>

#define MAX 200000

using namespace std;

class union_find {
private:
	vector<int> parents, ranks, count;

public:
	union_find(int n) : parents(n + 1, 0), ranks(n + 1, 0), count(n + 1, 1) {
		for(int i = 1; i <= n; ++i) {
			parents[i] = i;
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
			if(ranks[x] > ranks[y]) {
				parents[y] = parents[x];
				count[x] += count[y];
			} else {
				parents[x] = parents[y];
				count[y] += count[x];
			}

			if(ranks[x] == ranks[y]) ranks[x]++;
		}
	}

	int size(int u) {
		return count[find_set(u)];
	}
};

map<string, int> name_id;

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n, k = 0;
		scanf("%d", &n);

		union_find ufds(MAX);
		for(int i = 0; i < n; ++i) {
			char u[32], v[32];
			scanf(" %s %s", u, v);

			if(not name_id[u]) name_id[u] = ++k;
			if(not name_id[v]) name_id[v] = ++k;

			ufds.union_set(name_id[u], name_id[v]);
			printf("%d\n", ufds.size(name_id[u])); 
		}

		name_id.clear();
	}

	return 0;
}
