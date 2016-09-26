#include <bits/stdc++.h>

#define MAX 8192
#define oo 1e9

using namespace std;
using iv = tuple<int, int, int, int>;

vector<int> A, accum(MAX, 0), best(MAX, oo);

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<iv> queries;
	for(int i = 1; i <= m; ++i) {
		int cmd, l, r, v;
		scanf("%d %d %d %d", &cmd, &l, &r, &v);
		queries.push_back(iv(cmd, l, r, v));

		if(cmd == 1) {
			for(int i = l; i <= r; ++i) {
				accum[i] += v;
			}
		}

		if(cmd == 2) {
			for(int i = l; i <= r; ++i) {
				best[i] = min(best[i], v - accum[i]);
			}
		}
	}

	A = best;

	bool sol = true;
	for(auto& q : queries) {
		int cmd, l, r, v;
		tie(cmd, l, r, v) = q;

		if(cmd == 1) {
			for(int i = l; i <= r; ++i) {
				best[i] += v;
			}
		}

		if(cmd == 2) {
			int max_value = -oo;
			for(int i = l; i <= r; ++i) {
				max_value = max(max_value, best[i]);
			}

			if(max_value != v) { sol = false; break; }
		}
	}

	printf(sol ? "YES\n" : "NO\n");
	if(sol) {
		for(int i = 1; i <= n; ++i) {
			printf("%d ", A[i]);
		}
		printf("\n");
	}

	return 0;
}
