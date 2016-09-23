#include <bits/stdc++.h>

#define MAX 100005

using namespace std;

int A[MAX], bit_zero[MAX], bit_ngtv[MAX];

void update(int* fenwick, int idx, int value, int n) {
	while(idx <= n) {
		fenwick[idx] += value;
		idx += idx & -idx;
	}
}

int query(int* fenwick, int idx) {
	int sum = 0;
	while(idx) {
		sum += fenwick[idx];
		idx -= idx & -idx;
	}
	return sum;
}

int main(void) {
	int n, k;
	while(~scanf("%d %d", &n, &k)) {
		memset(bit_zero, 0, sizeof bit_zero);
		memset(bit_ngtv, 0, sizeof bit_ngtv);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &A[i]);
			update(bit_zero, i, A[i] == 0, n);
			update(bit_ngtv, i, A[i] < 0, n);
		}

		while(k--) {
			char cmd;
			scanf(" %c", &cmd);

			if(cmd == 'C') {
				int idx, value;
				scanf("%d %d", &idx, &value);
				if(A[idx]) {
					update(bit_zero, idx, value == 0 ?  1 : 0, n);
				} else {
					update(bit_zero, idx, value != 0 ? -1 : 0, n);
				}

				if(A[idx] >= 0) {
					update(bit_ngtv, idx, value < 0 ? 1 : 0, n);
				} else {
					update(bit_ngtv, idx, value >= 0 ? -1 : 0, n);
				}

				A[idx] = value;
			}

			if(cmd == 'P') {
				int i, j;
				scanf("%d %d", &i, &j);
				int num_zeros = query(bit_zero, j) - query(bit_zero, i - 1);
				int num_ngtvs = query(bit_ngtv, j) - query(bit_ngtv, i - 1);
				if(num_zeros) {
					printf("0");
				} else if(num_ngtvs & 1) {
					printf("-");
				} else {
					printf("+");
				}
			}
		}
		printf("\n");
	}

	return 0;
}
