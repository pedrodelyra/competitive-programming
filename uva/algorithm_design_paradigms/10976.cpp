#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

int main(void) {
	int k;
	while(scanf("%d", &k) != EOF) {
		vector<ii> solutions;
		for(int y = k + 1; y <= (k << 1); ++y) {
			if((y * k) % (y - k) == 0) {
				solutions.push_back(ii((y * k) / (y - k), y));
			}
		}

		printf("%d\n", solutions.size());
		for(auto& sol : solutions) {
			int x = sol.first, y = sol.second;
			printf("1/%d = 1/%d + 1/%d\n", k, x, y);
		}
	}

	return 0;
}
