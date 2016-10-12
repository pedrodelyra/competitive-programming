#include <bits/stdc++.h>

using namespace std;
using edge = tuple<int, int, int>;

class union_find {
private:
	vector<int> parents, rank;
	int size;

public:
	union_find(int n) : parents(n + 1), rank(n + 1, 0), size(n) {
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
		int x = find_set(u), y = find_set(v);
		if(rank[x] >= rank[y]) {
			parents[y] = parents[x];
		} else {
			parents[x] = parents[y];
		}

		if(rank[x] == rank[y]) ++rank[x];

		--size;
	}

	int count() const {
		return size;
	}
};

int main(void) {
	int n, m, max_edge;
	while(scanf("%d %d", &n, &m), max_edge = 0, n | m) {
		priority_queue<edge, vector<edge>, greater<edge>> edges;
		for(int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			edges.push(edge(w, u + 1, v + 1));
		}

		union_find ufds(n);
		while(not edges.empty() and ufds.count() > 1) {
			auto current_edge = edges.top();
			int w, u, v;
			tie(w, u, v) = current_edge;
			if(not ufds.same_set(u, v)) {
				max_edge = max(max_edge, w);
				ufds.union_set(u, v);
			}
			edges.pop();
		}
		printf(ufds.count() == 1 ? "%d\n" : "IMPOSSIBLE\n", max_edge);
	}
	return 0;
}
