#include <bits/stdc++.h>

#define MAX 3000
#define INF -1

using namespace std;

vector<int> graph[MAX];
unsigned dist[MAX], boom_day[MAX];

int bfs(int source) {
	queue<int> q;
	memset(dist, INF, sizeof dist);
	dist[source] = 0;
	q.push(source);

	memset(boom_day, 0, sizeof boom_day);
	while(not q.empty()) {
		int u = q.front();
		q.pop();

		boom_day[dist[u]]++;
		for(auto& v : graph[u]) {
			if(dist[v] == INF) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}

	boom_day[0] = 0;

	int max_boom_day = 0;
	for(int day = 1; day < MAX; ++day) {
		if(boom_day[day] > boom_day[max_boom_day]) {
			max_boom_day = day;
		}
	}

	return max_boom_day;
}

int main(void) {
	int n;
	scanf("%d", &n);
	for(int u = 0; u < n; ++u) {
		int m;
		scanf("%d", &m);
		while(m--) {
			int v;
			scanf("%d", &v);
			graph[u].push_back(v);
		}
	}

	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int source, max_boom_day;
		scanf("%d", &source);
		max_boom_day = bfs(source);
		printf(max_boom_day ? "%d %d\n" : "0\n", boom_day[max_boom_day], max_boom_day);
	}

	return 0;
}
