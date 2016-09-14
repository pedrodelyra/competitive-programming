#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n;
	while(scanf("%d", &n), n) {
		priority_queue<int, vector<int>, greater<int>> pq;
		for(int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			pq.push(x);
		}

		int total_cost = 0;
		while(pq.size() > 1) {
			int a = pq.top(); pq.pop();
			int b = pq.top(); pq.pop();
			int sum = a + b;
			pq.push(sum);
			total_cost += sum;
		}

		printf("%d\n", total_cost);
	}

	return 0;
}
