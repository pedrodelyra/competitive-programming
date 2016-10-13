#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, m;
	while(scanf("%d %d", &n, &m), (n | m)) {
		vector<int> dragons(n), knights(m);
		for(int i = 0; i < n; ++i)
			scanf("%d", &dragons[i]);

		for(int j = 0; j < m; ++j)
			scanf("%d", &knights[j]);

		sort(dragons.begin(), dragons.end());
		sort(knights.begin(), knights.end());

		int i, j, count = 0;
		for(i = 0, j = 0; i < m && j < n; ++i) {
			if(knights[i] >= dragons[j]) {
				count += knights[i];
				++j;
			}
		}

		printf(j == n ? "%d\n" : "Loowater is doomed!\n", count);
	}

	return 0;
}
