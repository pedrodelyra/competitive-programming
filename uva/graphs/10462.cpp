#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = pair<int, ii>;

bool forbidden_edges[128][128];

class union_find {
private:
	vector<int> parents, rank;
	int size;

public:
	union_find(int n) : parents(n + 1), rank(n + 1, 0), size(n) {
		for(int u = 1; u <= n; ++u)
			parents[u] = u;
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

			--size;
		}
	}

	int count() {
		return size;
	}
};

int build_mst(int n, vector<edge>& edges, vector<edge>& mst_edges) {
	union_find ufds(n);

	int mst_cost = 0;
	for(auto& current_edge : edges) {
		int w = current_edge.first, u = current_edge.second.first, v = current_edge.second.second;
		if(not ufds.same_set(u, v)) {
			ufds.union_set(u, v);
			mst_cost += w;
			mst_edges.push_back(current_edge);
		}

		if(ufds.count() == 1) break;
	}

	return ufds.count() == 1 ? mst_cost : INT_MAX;
}

int kruskall(int n, vector<edge>& edges) {
	union_find ufds(n);
	int min_cost = 0;
	for(auto& current_edge : edges) {
		int w = current_edge.first, u = current_edge.second.first, v = current_edge.second.second;

		if(forbidden_edges[u][v]) {
			forbidden_edges[u][v] = false;
			continue;
		}

		if(not ufds.same_set(u, v)) {
			ufds.union_set(u, v);
			min_cost += w;
		}
	}

	return min_cost;
}

int main(void) {
	int tests;
	scanf("%d", &tests);
	for(int tc = 1; tc <= tests; ++tc) {
		int n, m;
		scanf("%d %d", &n, &m);

		vector<edge> edges, mst_edges;
		for(int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			edges.push_back(edge(w, ii(u, v)));
		}

		sort(edges.begin(), edges.end());

		int mst_cost = build_mst(n, edges, mst_edges), _2nd_mst_cost = INT_MAX;
		for(auto& current_edge : mst_edges) {
			int u = current_edge.second.first, v = current_edge.second.second, current_cost;
			forbidden_edges[u][v] = true;
			current_cost = kruskall(n, edges);
			if(current_cost >= mst_cost)
				_2nd_mst_cost = min(_2nd_mst_cost, current_cost);
		}

		printf("Case #%d : ", tc);
		if(mst_cost < INT_MAX) {
			printf(_2nd_mst_cost < INT_MAX ? "%d\n" : "No second way\n", _2nd_mst_cost);
		} else {
			printf("No way\n");
		}
	}

	return 0;
}
