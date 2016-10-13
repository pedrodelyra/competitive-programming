#include <bits/stdc++.h>

#define MAX 128
#define UNVISITED -1

using namespace std;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;

vector<ii> mst[MAX];
int min_edges[MAX];

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

int bfs(int source, int destination) {
	queue<int> q;
	memset(min_edges, UNVISITED, sizeof min_edges);
	min_edges[source] = INT_MAX;
	q.push(source);
	while(not q.empty()) {
		int u = q.front();

		if(u == destination) break;

		for(auto& current_edge : mst[u]) {
			int w = current_edge.first, v = current_edge.second;
			if(min_edges[v] == UNVISITED) {
				min_edges[v] = min(min_edges[u], w);
				q.push(v);
			}
		}

		q.pop();
	}

	return min_edges[destination];
}

int main(void) {
	int n, m, tc = 0;
	while(scanf("%d %d", &n, &m), n | m) {
		priority_queue<edge> edges;
		for(int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			edges.push(edge(w - 1, u, v));
		}

		union_find ufds(n);
		while(not edges.empty() && ufds.count() > 1) {
			auto current_edge = edges.top();
			int w, u, v;
			tie(w, u, v) = current_edge;
			if(not ufds.same_set(u, v)) {
				ufds.union_set(u, v);
				mst[u].push_back(ii(w, v));
				mst[v].push_back(ii(w, u));
			}

			edges.pop();
		}

		int source, destination, tourists, min_edge;
		scanf("%d %d %d", &source, &destination, &tourists);

		min_edge = bfs(source, destination);
		printf("Scenario #%d\nMinimum Number of Trips = %d\n\n", ++tc, (int) ceil(tourists / (double) min_edge));

		for(int u = 1; u <= n; ++u)
			mst[u].clear();
	}

	return 0;
}
