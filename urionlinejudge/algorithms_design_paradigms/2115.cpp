#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

int main(void) {
	int n;
	while(~scanf("%d", &n)) {
		priority_queue<ii, vector<ii>, greater<ii>> pq;
		for(int i = 1; i <= n; ++i) {
			int d, p;
			scanf("%d %d", &d, &p);
			pq.push(ii(d, p));
		}
		int finish_time = 1;
		while(not pq.empty()) {
			auto current_job = pq.top(); pq.pop();
			if(finish_time < current_job.first) {
				finish_time = current_job.first;
			}
			finish_time += current_job.second;
		}
		printf("%d\n", finish_time);
	}
	return 0;
}
