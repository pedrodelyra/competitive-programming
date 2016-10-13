#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using car = pair<string, ii>;

int main(void) {
	int tc;
	scanf("%d", &tc);
	for(int t = 0; t < tc; ++t) {
		int n;
		scanf("%d", &n);

		vector<car> cars(n);
		for(int i = 0; i < n; ++i) {
			char car_name[255];
			int x, y;
			scanf(" %s %d %d", car_name, &x, &y);
			cars[i] = car(car_name, ii(x, y));
		}

		int q;
		scanf("%d", &q);

		if(t) printf("\n");
		while(q--) {
			int k, count = 0;
			scanf("%d", &k);

			car solution;
			for(auto& current_car : cars) {
				int x = current_car.second.first, y = current_car.second.second;
				if(x <= k && k <= y) {
					++count;
					solution = current_car;
				}
			}

			printf(count == 1 ? "%s\n" : "UNDETERMINED\n", solution.first.c_str());
		}
	}

	return 0;
}
