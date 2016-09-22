#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
	int n; ll sum = 0;
	scanf("%d", &n);

	vector<ll> A(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
		sum += A[i];
	}

	sort(A.begin(), A.end());

	ll ans = sum, current_sum = sum;
	for(int i = 0; i < n - 1; ++i) {
		current_sum -= A[i];
		ans += A[i] + current_sum;
	}

	printf("%lld\n", ans);

	return 0;
}
