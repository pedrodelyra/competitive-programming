#include <bits/stdc++.h>

#define MAX 100005

using namespace std;
using iii = tuple<int, int, int>;

int n, q, lazy[MAX << 2];
iii st[MAX << 2];

iii operator+(const iii& x, const iii& y) {
	int a, b, c, d, e, f;
	tie(a, b, c) = x;
	tie(d, e, f) = y;
	return iii(a + d, b + e, c + f);
}

void update_iii(iii& node, int updates) {
	int x, y, z;
	while(updates--) {
		int a, b, c;
		tie(a, b, c) = node;
		node = iii(c, a, b);
	}
}

void build_st(int p = 1, int l = 0, int r = n - 1) {
	if(l == r) {
		st[p] = iii(1, 0, 0);
	} else {
		int mid = (l + r) >> 1;
		build_st(p << 1, l, mid);
		build_st(p << 1 | 1, mid + 1, r);
		st[p] = st[p << 1] + st[p << 1 | 1];
	}
}

iii query(int i, int j, int p = 1, int l = 0, int r = n - 1) {
	if(i > r || j < l) return iii(0, 0, 0);

	if(lazy[p]) {
		update_iii(st[p], lazy[p] % 3);
		if(l != r) {
			lazy[p << 1] += lazy[p];
			lazy[p << 1 | 1] += lazy[p];
		}
		lazy[p] = 0;
	}

	if(l >= i and r <= j) return st[p];

	int mid = (l + r) >> 1;
	iii x = query(i, j, p << 1, l, mid);
	iii y = query(i, j, p << 1 | 1, mid + 1, r);
	return x + y;
}

void update(int i, int j, int p = 1, int l = 0, int r = n - 1) {
	if(lazy[p]) {
		update_iii(st[p], lazy[p] % 3);
		if(l != r) {
			lazy[p << 1] += lazy[p];
			lazy[p << 1 | 1] += lazy[p];
		}
		lazy[p] = 0;
	}

	if(i > r || j < l) return;

	if(l >= i and r <= j) {
		update_iii(st[p], 1);
		if(l != r) {
			lazy[p << 1]++;
			lazy[p << 1 | 1]++;
		}
		return;
	}
	int mid = (l + r) >> 1;
	update(i, j, p << 1, l, mid);
	update(i, j, p << 1 | 1, mid + 1, r);
	st[p] = st[p << 1] + st[p << 1 | 1];
}

int main(void) {
	while(~scanf("%d %d", &n, &q)) {
		build_st();
		while(q--) {
			char cmd;
			scanf(" %c", &cmd);
			if(cmd == 'C') {
				int a, b, x, y, z;
				scanf("%d %d", &a, &b);
				tie(x, y, z) = query(a - 1, b - 1);
				printf("%d %d %d\n", x, y, z);
			}

			if(cmd == 'M') {
				int a, b;
				scanf("%d %d", &a, &b);
				update(a - 1, b - 1);
			}
		}
		memset(lazy, 0, sizeof lazy);
		printf("\n");
	}
	return 0;
}
