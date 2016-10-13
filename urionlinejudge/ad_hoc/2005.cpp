#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, m;
	while(~scanf("%d %d", &n, &m)) {
		int rats[n + 1];
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &rats[i]);
		}

		int count = 0;
		for(int i = 1; i <= m; ++i) {
			int food, k1 = -1, k2 = -1, max_rat = 0, max_satisfied_rat = 0;
			scanf("%d", &food);
			for(int j = 1; j <= n; ++j) {
				if(rats[j] == 0) continue;

				if(rats[j] <= food && rats[j] > max_satisfied_rat) {
					max_satisfied_rat = rats[j];
					k1 = j;
				}

				if(rats[j] > max_rat) {
					max_rat = rats[j];
					k2 = j;
				}
			}

			if(~k1) {
				rats[k1] -= min(food, rats[k1]);
				count += rats[k1] == 0;
			} else if(~k2) {
				rats[k2] -= min(food, rats[k2]);
				count += rats[k2] == 0;
			}
		}
		printf("%d\n", count);
	}

	return 0;
}
