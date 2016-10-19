#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int tests;
	scanf("%d", &tests);
	for(int tc = 1; tc <= tests; ++tc) {
		int n; long long d;
		scanf("%d %lld", &n, &d);
		vector<long long> rocks {0, d};
		for(int i = 1; i <= n; ++i) {
			char type; long long x;
			scanf(" %c-%lld", &type, &x);
			rocks.push_back(x);
			if(type == 'B') rocks.push_back(x);
		}
		sort(rocks.begin(), rocks.end());

		long long max_jump = 0;
		for(int i = 2; i < rocks.size(); ++i) {
			max_jump = max(max_jump, rocks[i] - rocks[i - 2]);
		}

		for(int i = 3; i < rocks.size(); ++i) {
			max_jump = max(max_jump, rocks[i] - rocks[i - 2]);
		}
		printf("Case %d: %lld\n", tc, max_jump);
	}
	return 0;
}
