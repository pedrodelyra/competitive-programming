#include <bits/stdc++.h>

#define MAX 512
#define oo  0x3f3f3f3f

using namespace std;
using ii = pair<int, int>;

vector<ii> graph[MAX];
int dist[MAX][MAX << 2];

int bfs(int source, int destination) {
	queue<ii> q;
	memset(dist, oo, sizeof dist);
	q.push(ii(source, dist[source][0] = 0));
	while(not q.empty()) {
		auto current_state = q.front();
		int u, current_time;
		tie(u, current_time) = current_state;

		if(u == destination) return current_time;

		for(auto& edge : graph[u]) {
			int v = edge.first, t = edge.second;
			if((t and current_time % 3 == 0) or (t == 0 and current_time % 3)) {
				if(dist[v][current_time + 1] == oo) {
					q.push(ii(v, dist[v][current_time + 1] = current_time + 1));
				}
			}
		}
		q.pop();
	}
	return oo;
}

int main(void) {
	int n, m, source, destination;
	scanf("%d %d %d %d", &n, &source, &destination, &m);
	for(int i = 1; i <= m; ++i) {
		int u, v, s;
		scanf("%d %d %d", &u, &v, &s);
		graph[u].push_back(ii(v, s));
	}
	int dist = bfs(source, destination);
	printf(dist < oo ? "%d\n" : "*\n", dist);
	return 0;
}
