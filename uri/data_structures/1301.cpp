#include <bits/stdc++.h>

#define MAX 100005

using namespace std;

int n, k, A[MAX], st[MAX << 2];

void build_st(int p = 1, int L = 0, int R = n - 1) {
	if(L == R) {
		st[p] = A[L];
	} else {
		int mid = (L + R) >> 1;
		build_st(2 * p, L, mid);
		build_st(2 * p + 1, mid + 1, R);
		st[p] = st[2 * p] * st[2 * p + 1];
	}
}

int query(int i, int j, int p = 1, int L = 0, int R = n - 1) {
	if(i > R || j < L) {
		return 1;
	}

	if(L >= i && R <= j) {
		return st[p];
	}

	int mid = (L + R) >> 1;
	return query(i, j, 2 * p, L, mid) * query(i, j, 2 * p + 1, mid + 1, R);
}

void update(int index, int value, int p = 1, int L = 0, int R = n - 1) {
	if(L == R) {
		A[index] = st[p] = value;
	} else {
		int mid = (L + R) >> 1;

		if(index <= mid) {
			update(index, value, 2 * p, L, mid);
		} else {
			update(index, value, 2 * p + 1, mid + 1, R);
		}

		st[p] = st[2 * p] * st[2 * p + 1];
	}
}

int main(void) {
	while(~scanf("%d %d", &n, &k)) {
		for(int i = 0; i < n; ++i) {
			scanf("%d", &A[i]);
			if(A[i]) A[i] /= abs(A[i]);
		}

		memset(st, 0, sizeof st);
		build_st();

		while(k--) {
			char command;
			scanf(" %c", &command);
			if(command == 'C') {
				int index, value;
				scanf("%d %d", &index, &value);
				if(value) value /= abs(value);
				update(index - 1, value);
			}

			if(command == 'P') {
				int i, j, result;
				scanf("%d %d", &i, &j);
				result = query(i - 1, j - 1);

				printf("%c", result ? (result > 0 ? '+' : '-') : '0');
			}
		}
		printf("\n");
	}

	return 0;
}
