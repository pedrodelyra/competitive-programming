#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = pair<double, ii>;

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

			--this->size;
		}
	}

	int get_size(void) {
		return this->size;
	}
};

double min_spanning_forest(int n, int num_trees) {
	union_find ufds(n);

	double min_cost = 0.0;

	while(not edges.empty() && ufds.get_size() > num_trees) {
		edge current_edge = edges.top();
		double w = current_edge.first;
		int u = current_edge.second.first, v = current_edge.second.second;

		if(not ufds.same_set(u, v)) {
			ufds.union_set(u, v);
			min_cost = max(min_cost, w);
		}

		edges.pop();
	}

	return min_cost;
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int s, n;
		scanf("%d %d", &s, &n);

		vector<ii> outposts(n + 5);
		for(int i = 1; i <= n; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			outposts[i] = ii(x, y);
		}

		edges = priority_queue<edge, vector<edge>, greater<edge>>();
		for(int u = 1; u <= n; ++u) {
			for(int v = 1; v <= n; ++v) {
				if(u == v) continue;

				int x0 = outposts[u].first, y0 = outposts[u].second;
				int xf = outposts[v].first, yf = outposts[v].second;

				double dist = hypot(xf - x0, yf - y0);
				edges.push(edge(dist, ii(u, v)));
			}
		}

		printf("%.2lf\n", min_spanning_forest(n, s));
	}

	return 0;
}
