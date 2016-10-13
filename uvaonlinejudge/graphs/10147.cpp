#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = pair<double, ii>;

priority_queue<edge, vector<edge>, greater<edge>> edges;

class union_find {
private:
	vector<int> parents, rank;
	int count;

public:
	union_find(int n) : parents(n + 1), rank(n + 1, 0), count(n) {
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

			--count;
		}
	}

	int size() {
		return count;
	}
};

void kruskall(union_find& ufds) {
	while(not edges.empty() && ufds.size() > 1) {
		auto& current_edge = edges.top();
		int u = current_edge.second.first, v = current_edge.second.second;

		if(not ufds.same_set(u, v)) {
			printf("%d %d\n", u, v);
			ufds.union_set(u, v);
		}

		edges.pop();
	}
}

int main(void) {
	int tests;
	scanf("%d", &tests);
	for(int tc = 0; tc < tests; ++tc) {
		int n;
		scanf("%d", &n);

		vector<ii> cities(n + 1);
		union_find ufds(n);
		for(int i = 1; i <= n; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			cities[i] = ii(x, y);
		}

		edges = priority_queue<edge, vector<edge>, greater<edge>>();
		for(int u = 1; u < n; ++u) {
			for(int v = u + 1; v <= n; ++v) {
				int x0 = cities[u].first, y0 = cities[u].second;
				int xf = cities[v].first, yf = cities[v].second;
				double dist = sqrt((xf - x0) * (xf - x0) + (yf - y0) * (yf - y0));
				edges.push(edge(dist, ii(u, v)));
			}
		}

		int k;
		scanf("%d", &k);
		while(k--) {
			int u, v;
			scanf("%d %d", &u, &v);
			ufds.union_set(u, v);
		}

		if(tc) printf("\n");

		if(ufds.size() == 1) {
			printf("No new highways need\n");
		} else {
			kruskall(ufds);
		}
	}

	return 0;
}
