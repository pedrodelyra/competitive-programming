#include <bits/stdc++.h>

#define MAX 200005
#define oo  1 << 30

using namespace std;

int n, st[MAX << 4], A[MAX << 1];

int build_st(int p = 1, int l = 1, int r = n << 1) {
	if(l == r) {
		return st[p] = A[l];
	} else {
		int m = l + r >> 1;
		return st[p] = min(build_st(p << 1, l, m), build_st(p << 1 | 1, m + 1, r));
	}
}

int query(int i, int j, int p = 1, int l = 1, int r = n << 1) {
	if(i <= l and r <= j) {
		return st[p];
	} else if(i > r or j < l) {
		return oo;
	} else {
		int m = l + r >> 1;
		return min(query(i, j, p << 1, l, m), query(i, j, p << 1 | 1, m + 1, r));
	}
}

int main(void) {
	int max_sum = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &A[i]);
		A[i + n] = A[i];
	}
	for(int i = 1; i <= n << 1; ++i) {
		A[i] += A[i - 1];
	}
	build_st();
	for(int i = 2; i <= n << 1; ++i) {
		max_sum = max(max_sum, A[i] - query(max(i - n, 1), i - 1));
	}
	printf("%d\n", max_sum);
}
