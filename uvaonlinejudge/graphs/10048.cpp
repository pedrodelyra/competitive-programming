#include <bits/stdc++.h>

#define MAX 128
#define INF -1

using namespace std;
using ii = pair<int, int>;
using edge = pair<int, ii>;

priority_queue<edge, vector<edge>, greater<edge>> pq;
vector<ii> graph[MAX];
unsigned dist[MAX], parents[MAX];

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
			int x = find_set(u), y = find_set(v);

			if(rank[x] > rank[y]) {
				parents[y] = parents[x];
			} else {
				parents[x] = parents[y];
			}

			if(rank[x] > rank[y]) ++rank[x];
		}
	}
};

void kruskall(int n) {
	union_find ufds(n);

	while(not pq.empty()) {
		auto current = pq.top();
		pq.pop();

		int w = current.first, u = current.second.first, v = current.second.second;
		if(not ufds.same_set(u, v)) {
			ufds.union_set(u, v);
			graph[u].push_back(ii(w, v));
			graph[v].push_back(ii(w, u));
		}
	}
}

unsigned bfs(int source, int destination) {
	queue<int> q;
	memset(dist, -1, sizeof dist);
	memset(parents, 0, sizeof parents);
	dist[source] = 0;
	q.push(source);

	unsigned edges[MAX][MAX];
	while(not q.empty()) {
		int u = q.front();
		q.pop();

		for(auto& _edge : graph[u]) {
			int v = _edge.second, w = _edge.first;
			if(dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				parents[v] = u;
				edges[u][v] = edges[v][u] = w;
				q.push(v);
			}
		}
	}

	unsigned u = destination, max_edge = 0;
	while(parents[u]) {
		int v = parents[u];
		max_edge = max(max_edge, edges[u][v]);
		u = v;
	}

	return dist[destination] < INF ? max_edge : INF;
}

int main(void) {
	int n, m, k, tc = 0;
	while(scanf("%d %d %d", &n, &m, &k), (n | m | k)) {
		for(int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			pq.push(edge(w, ii(u, v)));
		}

		kruskall(n);

		if(tc) { printf("\n"); }
		printf("Case #%d\n", ++tc);

		while(k--) {
			unsigned source, destination, thinnest_edge;
			scanf("%d %d", &source, &destination);
			thinnest_edge = bfs(source, destination);
			printf(thinnest_edge < INF ? "%d\n" : "no path\n", thinnest_edge); 
		}

		for(int u = 1; u <= n; ++u)
			graph[u].clear();
	}

	return 0;
}
