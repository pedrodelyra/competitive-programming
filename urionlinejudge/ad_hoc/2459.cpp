#include <bits/stdc++.h>

using namespace std;
using edge = tuple<int, int, int, int>;

class union_find {
private:
	vector<int> parents, rank;
	int size;

public:
	union_find(int n) : parents(n + 1), rank(n + 1, 0), size(n) {
		for(int u = 1; u <= n; ++u) parents[u] = u;
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

	int count(void) const {
		return size;
	}
};

const int RAILWAY = 0, HIGHWAY = 1;

int kruskall(int n, priority_queue<edge, vector<edge>, greater<edge>>& edges) {
	union_find ufds(n); int mst_cost = 0;
	while(not edges.empty() and ufds.count() > 1) {
		auto current_edge = edges.top();
		int t, w, u, v;
		tie(t, w, u, v) = current_edge;
		if(not ufds.same_set(u, v)) {
			ufds.union_set(u, v);
			mst_cost += w;
		}
		edges.pop();
	}
	return mst_cost;
}

int main(void) {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	priority_queue<edge, vector<edge>, greater<edge>> edges;
	for(int i = 1; i <= m + k; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edges.push(edge(i <= m ? RAILWAY : HIGHWAY, w, u, v));
	}
	printf("%d\n", kruskall(n, edges));
	return 0;
}
