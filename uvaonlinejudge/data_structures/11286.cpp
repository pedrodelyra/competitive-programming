#include <bits/stdc++.h>

using namespace std;

map<vector<int>, int> combs;

int main(void) {
	int n;
	while(scanf("%d", &n), n) {
		int max_comb = 0;
		for(int i = 0; i < n; ++i) {
			vector<int> v(5);
			for(int j = 0; j < 5; ++j) {
				scanf("%d", &v[j]);
			}

			sort(v.begin(), v.end());
			max_comb = max(max_comb, ++combs[v]);
		}

		int students = 0;
		for(auto& comb : combs) {
			if(comb.second == max_comb)
				students += comb.second;
		}

		printf("%d\n", students);
		combs.clear();
	}

	return 0;
}
