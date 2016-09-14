#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, m;
	while(scanf("%d %d", &n, &m), (n | m)) {
		set<int> cds;
		for(int i = 0; i < n; ++i) {
			int cd;
			scanf("%d", &cd);
			cds.insert(cd);
		}

		int result = 0;
		for(int i = 0; i < m; ++i) {
			int cd;
			scanf("%d", &cd);
			result += cds.count(cd);
		}

		printf("%d\n", result);
	}

	return 0;
}
