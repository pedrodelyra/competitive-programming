#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using dd = pair<double, double>;
using edge = pair<double, ii>;

priority_queue<edge, vector<edge>, greater<edge>> edges;

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

double kruskall(int n) {
	union_find ufds(n);
	double mst_cost = 0.0;
	while(not edges.empty()) {
		auto current_edge = edges.top();
		double w = current_edge.first;
		int u = current_edge.second.first, v = current_edge.second.second;

		if(not ufds.same_set(u, v)) {
			ufds.union_set(u, v);
			mst_cost += w;
		}

		edges.pop();
	}

	return mst_cost;
}

int main(void) {
	int tests;
	scanf("%d", &tests);
	for(int tc = 0; tc < tests; ++tc) {
		int n;
		scanf("%d", &n);

		vector<dd> points(n + 1);
		for(int i = 1; i <= n; ++i) {
			double x, y;
			scanf("%lf %lf", &x, &y);
			points[i] = dd(x, y);
		}

		for(int u = 1; u < n; ++u) {
			for(int v = u + 1; v <= n; ++v) {
				double x0 = points[u].first, y0 = points[u].second;
				double xf = points[v].first, yf = points[v].second;
				edges.push(edge(hypot(xf - x0, yf - y0), ii(u, v)));
			}
		}

		if(tc) printf("\n");

		printf("%.2lf\n", kruskall(n));
	}

	return 0;
}
