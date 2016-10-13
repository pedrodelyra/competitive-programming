#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using iii = pair<ii, int>;

int main(void) {
	int n, m;
	while(scanf("%d %d", &n, &m), (n | m)) {
		vector<iii> constraints(m);
		for(int i = 0; i < m; ++i) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			constraints[i] = iii(ii(a, b), c);
		}

		int result = 0, perms[8] = {0, 1, 2, 3, 4, 5, 6, 7};
		do {
			int count = 0;
			for(auto& constraint : constraints) {
				int a = constraint.first.first, b = constraint.first.second, c = constraint.second;
				int idx_a, idx_b;
				for(int i = 0; i < n; ++i) {
					if(perms[i] == a) idx_a = i;
					if(perms[i] == b) idx_b = i;
				}

				if(c > 0)
					count += abs(idx_a - idx_b) <= c;
				else
					count += abs(idx_a - idx_b) >= -c;
			}

			result += count == constraints.size();
		} while(next_permutation(perms, perms + n));

		printf("%d\n", result);
	}

	return 0;
}
