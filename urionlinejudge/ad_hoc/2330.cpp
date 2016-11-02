#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

int tasks[1 << 20], frequences[1 << 10];

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		scanf("%d", &tasks[i]);
	}

	priority_queue<ii, vector<ii>, greater<ii>> pq;
	for(int i = 1; i <= n; ++i) {
		pq.push(ii(0, i));
	}

	for(int i = 1; i <= m; ++i) {
		auto current = pq.top(); pq.pop();
		frequences[current.second]++;
		pq.push(ii(current.first + tasks[i], current.second));
	}

	for(int i = 1; i <= n; ++i) {
		printf("%d %d\n", i, frequences[i]);
	}
	return 0;
}
