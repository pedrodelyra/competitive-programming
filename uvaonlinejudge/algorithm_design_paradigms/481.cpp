#include <bits/stdc++.h>

#define MAX 1000005

using namespace std;

int A[MAX], L[MAX], P[MAX], id[MAX], size, k;

void build_lis(stack<int>& s, int idx) {
	if(idx < 0) return;
	s.push(A[idx]);
	build_lis(s, P[idx]);
}

int main(void) {
	int last_lis_idx = 0;
	while(scanf("%d", &A[k]) != EOF) {
		int pos = lower_bound(L, L + size, A[k]) - L;
		L[pos] = A[k];
		id[pos] = k;
		P[k] = pos > 0 ? id[pos - 1] : -1;

		if(size == pos) {
			++size;
			last_lis_idx = k;
		}

		++k;
	}

	stack<int> s;
	build_lis(s, last_lis_idx);

	printf("%d\n-\n", size);
	while(not s.empty()) {
		int x = s.top();
		printf("%d\n", x);
		s.pop();
	}

	return 0;
}
