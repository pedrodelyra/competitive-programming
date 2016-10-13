#include <bits/stdc++.h>

#define MAX 100005

using namespace std;
using ll = long long int;

int n, k;
ll A[MAX], st[MAX << 2], lazy[MAX << 2];

void build_st(int p = 1, int L = 0, int R = n - 1) {
	if(L == R) {
		st[p] = A[L];
	} else {
		int mid = (L + R) >> 1;
		build_st(2 * p, L, mid);
		build_st(2 * p + 1, mid + 1, R);
		st[p] = st[2 * p] + st[2 * p + 1];
	}
}

ll query(int p, int L, int R, int i, int j) {	
	if(i > R || j < L) return 0;

	if(lazy[p]) {
		st[p] += (R - L + 1) * lazy[p];

		if(L != R) {
			lazy[2 * p] += lazy[p];
			lazy[2 * p + 1] += lazy[p];
		}

		lazy[p] = 0;
	}

	if(L >= i && R <= j) {
		return st[p];
	}

	int mid = (L + R) >> 1;
	ll q1 = query(2 * p, L, mid, i, j);
	ll q2 = query(2 * p + 1, mid + 1, R, i, j);
	return q1 + q2;
}

void update(int p, int L, int R, int i, int j, ll value) { 
	if(lazy[p]) {
		st[p] += (R - L + 1) * lazy[p];

		if(L != R) {
			lazy[2 * p] += lazy[p];
			lazy[2 * p + 1] += lazy[p];
		}

		lazy[p] = 0;
	}
  
	if(i > R || j < L) return;
    
	if(L >= i && R <= j) {
		st[p] += (R - L + 1) * value;

		if(L != R) {
			lazy[2 * p] += value;
			lazy[2 * p + 1] += value;
		}

		return;
	}

	int mid = (L + R) >> 1;
	update(2 * p, L, mid, i, j, value);
	update(2 * p + 1, mid + 1, R, i, j, value);

	st[p] = st[2 * p] + st[2 * p + 1];
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		scanf("%d %d", &n, &k);
		memset(A, 0, sizeof A);
		memset(lazy, 0, sizeof lazy);
		build_st();
		for(int i = 0; i < k; ++i) {
			int command;
			scanf("%d", &command);
			if(command) {
				int a, b;
				scanf("%d %d", &a, &b);
				printf("%lld\n", query(1, 0, n - 1, a - 1, b - 1));
			} else {
				int a, b, v;
				scanf("%d %d %d", &a, &b, &v);
				update(1, 0, n - 1, a - 1, b - 1, v);
			}
		}
	}

	return 0;
}
