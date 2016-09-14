#include <bits/stdc++.h>

#define MAX 128

using namespace std;
using ii = pair<int, int>;
using edge = pair<int, ii>;

vector<edge> mst_edges;
bool forbidden_edges[MAX][MAX];

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

int build_mst(int n, vector<edge>& edges) {
	union_find ufds(n);

	int min_cost = 0;
	for(auto& current_edge : edges) {
		int w = current_edge.first, u = current_edge.second.first, v = current_edge.second.second;

		if(not ufds.same_set(u, v)) {
			ufds.union_set(u, v);
			min_cost += w;
			mst_edges.push_back(edge(w, ii(u, v)));
		}
	}

	return min_cost;
}

int kruskall(int n, vector<edge>& edges) {
	union_find ufds(n);

	int min_cost = 0;
	for(auto& current_edge : edges) {
		int w = current_edge.first, u = current_edge.second.first, v = current_edge.second.second;

		if(forbidden_edges[u][v]) continue;

		if(not ufds.same_set(u, v)) {
			ufds.union_set(u, v);
			min_cost += w;
		}
	}

	return min_cost;
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n, m;
		scanf("%d %d", &n, &m);

		vector<edge> edges;
		for(int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			edges.push_back(edge(w, ii(u, v)));
		}

		sort(edges.begin(), edges.end());

		int mst = build_mst(n, edges), _2nd_mst = (1 << 30);
		memset(forbidden_edges, false, sizeof forbidden_edges);
		for(auto& current_edge : mst_edges) {
			int u = current_edge.second.first, v = current_edge.second.second, min_cost;
			forbidden_edges[u][v] = true;
			min_cost = kruskall(n, edges);
			if(min_cost >= mst) _2nd_mst = min(_2nd_mst, min_cost);
			forbidden_edges[u][v] = false;
		}

		printf("%d %d\n", mst, _2nd_mst);
		mst_edges.clear();
	}

	return 0;
}
