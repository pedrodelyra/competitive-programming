#include <bits/stdc++.h>

#define MAX 100005

using namespace std;

int A[MAX], fenwick[MAX];

void update(int idx, int value, int n) {
	while(idx <= n) {
		fenwick[idx] += value;
		idx += idx & -idx;
	}
}

int query(int idx) {
	int sum = 0;
	while(idx) {
		sum += fenwick[idx];
		idx -= idx & -idx;
	}
	return sum;
}

int main(void) {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &A[i]);
	for(int i = 1; i <= n; ++i) update(i, A[i], n);
	char cmd;
	while(~scanf(" %c", &cmd)) {
		int idx;
		scanf("%d", &idx);

		if(cmd == '?') printf("%d\n", query(idx - 1));

		if(cmd == 'a') update(idx, -A[idx], n);
	}

	return 0;
}
