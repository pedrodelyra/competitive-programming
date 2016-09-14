#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;

		bool is_stack, is_queue, is_pq;
		is_stack = is_queue = is_pq = true;
		for(int i = 0; i < n; ++i) {
			int command, x;
			scanf("%d %d", &command, &x);
			if(command == 1) {
				s.push(x);
				q.push(x);
				pq.push(x);
			} else {
				int a = -1, b = -1, c = -1;

				if(not s.empty()) a = s.top();
				if(not q.empty()) b = q.front();
				if(not pq.empty()) c = pq.top();

				is_stack = is_stack && a == x;
				is_queue = is_queue && b == x;
				is_pq    = is_pq    && c == x;

				if(not s.empty()) s.pop();
				if(not q.empty()) q.pop();
				if(not pq.empty()) pq.pop();
			}
		}

		if(!is_stack && !is_queue && !is_pq) {
			printf("impossible\n");
		} else if(is_stack && !is_queue && !is_pq) {
			printf("stack\n");
		} else if(!is_stack && is_queue && !is_pq) {
			printf("queue\n");
		} else if(!is_stack && !is_queue && is_pq) {
			printf("priority queue\n");
		} else {
			printf("not sure\n");
		}
	}

	return 0;
}
