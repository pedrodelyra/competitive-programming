#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

int t[128];

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<ii> cars;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			int s;
			scanf("%d", &s);
			t[i] += s;
		}
		cars.push_back(ii(t[i], i));
	}
	sort(cars.begin(), cars.end());
	for(int i = 0; i < 3; ++i) {
		printf("%d\n", cars[i].second);
	}
	return 0;
}
