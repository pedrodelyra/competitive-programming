#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = pair<int, ii>;

set<edge> mst_edges;

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

void kruskall(int n, vector<edge>& edges) {
	union_find ufds(n);

	for(auto& current_edge : edges) {
		int w = current_edge.first, u = current_edge.second.first, v = current_edge.second.second;

		if(not ufds.same_set(u, v)) {
			ufds.union_set(u, v);
			mst_edges.insert(current_edge);
		}
	}
}

int main(void) {
	int n, m;
	while(scanf("%d %d", &n, &m), (n | m)) {
		vector<edge> edges;
		for(int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			edges.push_back(edge(w, ii(u, v)));
		}

		sort(edges.begin(), edges.end());

		kruskall(n, edges);

		vector<edge> discarded_edges;
		for(auto& current_edge : edges) {
			if(mst_edges.count(current_edge) == 0) {
				discarded_edges.push_back(current_edge);
			}
		}

		bool flag = true;
		for(auto& current_edge : discarded_edges) {
			if(flag) { flag = false; } else { printf(" "); }
			printf("%d", current_edge.first);
		}

		printf(discarded_edges.empty() ? "forest\n" : "\n");
		mst_edges.clear();
	}

	return 0;
}
