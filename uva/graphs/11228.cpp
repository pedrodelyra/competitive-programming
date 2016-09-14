#include <bits/stdc++.h>

#define MAX 1024

using namespace std;
using ii = pair<int, int>;
using edge = pair<double, ii>;

class union_find {
private:
	vector<int> parents, rank;

public:
	union_find(int n) : parents(n + 1), rank(n + 1, 0) {
		for(int i = 1; i <= n; ++i) {
			parents[i] = i;
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
			int x = parents[u], y = parents[v];

			if(rank[x] > rank[y]) {
				parents[y] = parents[x];
			} else {
				parents[x] = parents[y];
			}

			if(rank[x] == rank[y]) ++rank[x];
		}
	}
};

priority_queue<edge, vector<edge>, greater<edge>> pq;
int total_states;
double roads, railroads;

void kruskall(int n, int k) {
	union_find ufds(n);

	roads = railroads = total_states = 0;
	while(not pq.empty()) {
		auto current = pq.top();
		pq.pop();

		double w = current.first;
		int u = current.second.first, v = current.second.second;

		if(not ufds.same_set(u, v)) {
			ufds.union_set(u, v);
			if(w > k) {
				railroads += w;
				total_states++;
			} else {
				roads += w;
			}
		}
	}
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	for(int t = 1; t <= tc; ++t) {
		int n, k;
		scanf("%d %d", &n, &k);

		ii coordinates[MAX];
		for(int u = 1; u <= n; ++u) {
			int x, y;
			scanf("%d %d", &x, &y);
			coordinates[u].first = x;
			coordinates[u].second = y;
		}

		for(int u = 1; u <= n; ++u) {
			for(int v = 1; v <= n; ++v) {
				if(u == v) continue;

				int x0 = coordinates[u].first, x = coordinates[v].first;
				int y0 = coordinates[u].second, y = coordinates[v].second;
				double dist = sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0));

				pq.push(edge(dist, ii(u, v)));
			}
		}

		kruskall(n, k);
		printf("Case #%d: %d %d %d\n", t, total_states + 1, (int) (roads + 0.5), (int) (railroads + 0.5));
	}

	return 0;
}
