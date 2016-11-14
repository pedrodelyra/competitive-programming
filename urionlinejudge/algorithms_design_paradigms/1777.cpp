#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

void merge_overlapping_intervals(vector<ii>& A, vector<ii>& overlapping_intervals) {
	ii current_interval = A[0];
	for(int i = 1; i < A.size(); ++i) {
		if(current_interval.second >= A[i].first) {
			current_interval = ii(min(current_interval.first, A[i].first), max(current_interval.second, A[i].second));
		} else {
			overlapping_intervals.push_back(current_interval);
			current_interval = A[i];
		}
	}
	overlapping_intervals.push_back(current_interval);
}

int main(void) {
	int tests;
	scanf("%d", &tests);
	for(int tc = 1; tc <= tests; ++tc) {
		int n, m;
		scanf("%d %d", &n, &m);
		vector<ii> A(m), B;
		for(int i = 0; i < m; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			A[i] = ii(a, b);
		}
		sort(A.begin(), A.end());
		merge_overlapping_intervals(A, B);
		int k, count = 0;
		scanf("%d", &k);
		for(int j = 0; j < k; ++j) {
			int x;
			scanf("%d", &x);
			int l = 0, h = B.size() - 1;
			while(l <= h) {
				int i = (l + h) >> 1;
				if(B[i].first <= x and x <= B[i].second) {
					++count;
					break;
				} else if(x > B[i].second) {
					l = i + 1;
				} else {
					h = i - 1;
				}
			}
		}
		printf("Caso #%d: %d\n", tc, count);
	}
	return 0;
}
