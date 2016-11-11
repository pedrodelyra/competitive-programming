#include <bits/stdc++.h>

#define MAX 20005
#define MAX_LOG 20
#define oo  0x3f3f3f3f

using namespace std;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;

vector<ii> mst[MAX];

class union_find {
private:
	vector<int> rank, parents;
	int size;

public:
	union_find(int n) : rank(n + 1, 0), parents(n + 1), size(n) {
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
		int x = find_set(u), y = find_set(v);

		if(rank[x] >= rank[y]) {
			parents[y] = parents[x];
		} else {
			parents[x] = parents[y];
		}

		if(rank[x] == rank[y]) ++rank[x];

		--size;
	}

	int count() const {
		return size;
	}
};

void kruskall(int n, priority_queue<edge>& edges) {
	union_find ufds(n);
	while(not edges.empty() and ufds.count() > 1) {
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
}

int visited[MAX], p[MAX], pw[MAX], level[MAX], A[MAX][MAX_LOG], m[MAX][MAX_LOG];

void dfs(int u, int h) {
	visited[u] = true;
	level[u] = h;
	for(auto& current_edge : mst[u]) {
		int w = current_edge.first, v = current_edge.second;
		if(not visited[v]) {
			p[v] = u, pw[v] = w;
			dfs(v, h + 1);
		}
	}
}

void preprocess(int n) {
	memset(A, -1, sizeof A);
	memset(m, -1, sizeof m);
	for(int i = 1; i <= n; ++i) {
		A[i][0] = p[i];
		m[i][0] = pw[i];
	}
	for(int j = 1; 1 << j <= n; ++j) {
		for(int i = 1; i <= n; ++i) {
			if(~A[i][j - 1]) {
				A[i][j] = A[A[i][j - 1]][j - 1];
				m[i][j] = min(m[i][j - 1], m[A[i][j - 1]][j - 1]);
			}
		}
	}
}

int query(int u, int v) {
	if(level[u] < level[v]) swap(u, v);

	int lg, ans = oo;
	for(lg = 1; 1 << lg <= level[u]; ++lg);
	lg--;

	for(int i = lg; i >= 0; --i) {
		if(level[u] - (1 << i) >= level[v]) {
			ans = min(ans, min(pw[u], m[u][i]));
			u = A[u][i];
		}
	}

	if(u == v) {
		return ans;
	} else {
		for(int i = lg; i >= 0; --i) {
			if(~A[u][i] and A[u][i] != A[v][i]) {
				ans = min(ans, min(min(pw[u], pw[v]), min(m[u][i], m[v][i])));
				u = A[u][i];
				v = A[v][i];
			}
		}
		return min(ans, min(pw[u], pw[v]));
	}
}

int main(void) {
	int n, m, q, root = 1;
	while(~scanf("%d %d %d", &n, &m, &q)) {
		priority_queue<edge> edges;
		for(int i = 1; i <= m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			edges.push(edge(w, min(u, v), max(u, v)));
		}
		kruskall(n, edges);
		p[root] = root, pw[root] = oo, dfs(root, 0);
		preprocess(n);
		for(int i = 1; i <= q; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			printf("%d\n", query(u, v));
		}

		memset(visited, false, sizeof visited);
		for(int u = 1; u <= n; ++u) mst[u].clear();
	}
	return 0;
}
