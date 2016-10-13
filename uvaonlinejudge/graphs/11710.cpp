#include <bits/stdc++.h>

#define INF (1 << 30)

using namespace std;
using edge = tuple<int, int, int>;

priority_queue<edge, vector<edge>, greater<edge>> edges;

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

int kruskall(int n) {
	union_find ufds(n);
	int mst_cost = 0;
	while(not edges.empty()) {
		auto current_edge = edges.top();
		int w, u, v;
		tie(w, u, v) = current_edge;
		if(not ufds.same_set(u, v)) {
			ufds.union_set(u, v);
			mst_cost += w;
		}
		edges.pop();
	}

	return ufds.count() == 1 ? mst_cost : INF;
}

int main(void) {
	int n, m;
	while(scanf("%d %d", &n, &m), n | m) {
		map<string, int> station_id;
		for(int u = 1; u <= n; ++u) {
			char name[255];
			scanf(" %s", name);
			station_id[name] = u;
		}

		for(int i = 1; i <= m; ++i) {
			int cost;
			char station1[255], station2[255];
			scanf(" %s %s %d", station1, station2, &cost);
			
			int u = station_id[station1], v = station_id[station2];
			edges.push(edge(cost, u, v));
		}

		char home[255];
		scanf(" %s", home);

		int mst_cost = kruskall(n);
		printf(mst_cost < INF ? "%d\n" : "Impossible\n", mst_cost);
	}

	return 0;
}
