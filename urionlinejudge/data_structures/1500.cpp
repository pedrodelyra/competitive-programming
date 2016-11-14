#include <bits/stdc++.h>

#define MAX 100005

using namespace std;
using lld = long long int;

int n, k;
lld st[MAX << 2], lazy[MAX << 2];

lld query(int i, int j, int p = 1, int l = 0, int r = n - 1) {
	if(i > r or j < l) return 0;

	if(lazy[p]) {
		st[p] += (r - l + 1) * lazy[p];
		if(l != r) {
			lazy[p << 1] += lazy[p];
			lazy[p << 1 | 1] += lazy[p];
		}
		lazy[p] = 0;
	}

	if(l >= i and r <= j) {
		return st[p];
	}

	int mid = (l + r) >> 1;
	lld x = query(i, j, p << 1, l, mid);
	lld y = query(i, j, p << 1 | 1, mid + 1, r);
	return x + y;
}

void update(int i, int j, lld value, int p = 1, int l = 0, int r = n - 1) {
	if(lazy[p]) {
		st[p] += (r - l + 1) * lazy[p];
		if(l != r) {
			lazy[p << 1] += lazy[p];
			lazy[p << 1 | 1] += lazy[p];
		}
		lazy[p] = 0;
	}
  
	if(i > r or j < l) return;
    
	if(l >= i and r <= j) {
		st[p] += (r - l + 1) * value;
		if(l != r) {
			lazy[p << 1] += value;
			lazy[p << 1 | 1] += value;
		}
		return;
	}

	int mid = (l + r) >> 1;
	update(i, j, value, p << 1, l, mid);
	update(i, j, value, p << 1 | 1, mid + 1, r);
	st[p] = st[p << 1] + st[p << 1 | 1];
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		scanf("%d %d", &n, &k);
		memset(st,   0, sizeof st);
		memset(lazy, 0, sizeof lazy);
		for(int i = 0; i < k; ++i) {
			int command;
			scanf("%d", &command);
			if(command) {
				int a, b;
				scanf("%d %d", &a, &b);
				printf("%lld\n", query(a - 1, b - 1));
			} else {
				int a, b, v;
				scanf("%d %d %d", &a, &b, &v);
				update(a - 1, b - 1, v);
			}
		}
	}
	return 0;
}
