#include <bits/stdc++.h>

#define MAX 100005

using namespace std;

int n, A[MAX], fenwick[MAX];

int query(int idx) {
	int sum = 0;
	while(idx) {
		sum += fenwick[idx];
		idx -= idx & -idx;
	}
	return sum;
}

void update(int idx, int value) {
	while(idx <= n) {
		fenwick[idx] += value;
		idx += idx & -idx;
	}
}

int main(void) {
	int pairs = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &A[i]);
	}
	for(int i = n; i >= 1; --i) {
		pairs += query(A[i]);
		update(A[i], 1);
	}
	printf("%d\n", pairs);
	return 0;
}
