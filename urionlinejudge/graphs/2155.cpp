#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

int main(void) {
	int tests;
	scanf("%d", &tests);
	vector<ii> coordinates(8);
	for(int tc = 1; tc <= tests; ++tc) {
		int x, y;
		scanf("%d %d", &x, &y);
		coordinates[4]= ii(x, y);
		for(int i = 1, id; i <= 6; ++i) {
			scanf("%d %d %d", &id, &x, &y);
			coordinates[id] = ii(x, y);
		}
		double min_dist = 1e12, dist[8][8];
		for(int i = 1; i <= 7; ++i) {
			for(int j = 1; j <= 7; ++j) {
				dist[i][j] = dist[j][i] = hypot(coordinates[i].first - coordinates[j].first, coordinates[i].second - coordinates[j].second);
			}
		}
		vector<int> sol, perm = {1, 2, 3, 5, 6, 7};
		do {
			double current_dist = dist[4][perm[0]] + dist[perm[5]][4];
			for(int i = 0; i < 5; ++i) {
				current_dist += dist[perm[i]][perm[i + 1]];
			}
			if(current_dist < min_dist) {
				min_dist = current_dist;
				sol = perm;
			}
		} while(next_permutation(perm.begin(), perm.end()));
		printf("Caso %d:\n4", tc);
		for(int i = 0; i < 6; ++i) {
			printf("->%d", sol[i]);
		}
		printf("->4: %.5lf\n", min_dist);
	}
	return 0;
}
