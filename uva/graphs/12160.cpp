#include <bits/stdc++.h>

#define MAX 10000
#define INF -1

using namespace std;

unsigned dist[MAX];

int main(void) {
	int source, destination, n, tc = 0;
	while(scanf("%d %d %d", &source, &destination, &n), (source | destination | n)) {
		vector<int> buttons(n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &buttons[i]);
		}

		queue<int> q;
		memset(dist, INF, sizeof dist);
		dist[source] = 0;
		q.push(source);

		while(not q.empty()) {
			int u = q.front();
			q.pop();

			for(int& btn : buttons) {
				int v = (u + btn) % MAX;
				if(dist[v] == INF) {
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}

		printf("Case %d: ", ++tc);
		printf(dist[destination] < INF ? "%d\n" : "Permanently Locked\n", dist[destination]);
	}

	return 0;
}
