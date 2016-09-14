#include <bits/stdc++.h>

using namespace std;
using edge = tuple<int, int, int>;

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

	int count(void) {
		return size;
	}
};

int main(void) {
	int tests;
	scanf("%d", &tests);
	for(int tc = 1; tc <= tests; ++tc) {
		int n, m, airport_cost, total_cost = 0;
		scanf("%d %d %d", &n, &m, &airport_cost);

		priority_queue<edge, vector<edge>, greater<edge>> edges;
		for(int i = 1; i <= m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			edges.push(edge(w, u, v));
		}

		union_find ufds(n);
		while(not edges.empty() && ufds.count() > 1) {
			auto current_edge = edges.top();
			int w, u, v;
			tie(w, u, v) = current_edge;

			if(w >= airport_cost) break;

			if(not ufds.same_set(u, v)) {
				ufds.union_set(u, v);
				total_cost += w;
			}

			edges.pop();
		}

		total_cost += ufds.count() * airport_cost;

		printf("Case #%d: %d %d\n", tc, total_cost, ufds.count());
	}

	return 0;
}
