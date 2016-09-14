#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = pair<int, ii>;

class union_find {
	vector<int> parents, rank;

	public:
	union_find(int v) : parents(v + 1, 0), rank(v + 1, 0) {
		for(int i = 1; i <= v; ++i) {
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
		if(same_set(u, v))
			return;

		int p = find_set(u);
		int q = find_set(v);

		if(rank[p] >= rank[q])
			parents[q] = p;
		else
			parents[p] = q;

		if(rank[p] == rank[q])
			rank[p]++;
	}
};


priority_queue<edge, vector<edge>, greater<edge>> pq;	
int kruskall(int n) {
	union_find ufds(n);

	int min_cost = 0;
	while(pq.empty() == 0) {
		auto current_edge = pq.top();
		pq.pop();

		int w = current_edge.first, u = current_edge.second.first, v = current_edge.second.second;
		if(not ufds.same_set(u, v)) {
			ufds.union_set(u, v);
			min_cost += w;
		}
	}

	return min_cost;
}

int main(void) {
	int n, m;
	while(scanf("%d %d", &n, &m), (n | m)) {
		int total_cost = 0;
		for(int i = 1; i <= m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			pq.push(edge(w, ii(u + 1, v + 1)));			
			total_cost += w;
		}

		printf("%d\n", total_cost - kruskall(n));
	}

	return 0;
}
