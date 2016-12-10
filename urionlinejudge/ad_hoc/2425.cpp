#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 1; i <= n; ++i) {
		pq.push(0);
	}
	int count = 0;
	for(int i = 1; i <= m; ++i) {
		int t, dt;
		scanf("%d %d", &t, &dt);
		int u = pq.top(); pq.pop();
		pq.push(max(u, t) + dt);
		if(u - t > 20) count++;
	}
	printf("%d\n", count);
	return 0;
}
