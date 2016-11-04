#include <bits/stdc++.h>

using namespace std;
using lld = long long int;
using ll  = pair<lld, lld>;

int main(void) {
	int n, d;
	scanf("%d %d", &n, &d);
	vector<ll> A(n + 1);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld %lld", &A[i].first, &A[i].second);
	}
	sort(A.begin() + 1, A.end());
	vector<lld> sum(n + 1, 0);
	for(int i = 1; i <= n; ++i) {
		sum[i] = A[i].second + sum[i - 1];
	}
	lld ans = 0;
	for(int i = 1; i <= n; ++i) {
		int j = i, low = i, high = n;
		while(low <= high) {
			int mid = (low + high) >> 1;
			if(A[mid].first < A[i].first + d) {
				j = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		ans = max(ans, sum[j] - sum[i - 1]);
	}
	printf("%lld\n", ans);
	return 0;
}
