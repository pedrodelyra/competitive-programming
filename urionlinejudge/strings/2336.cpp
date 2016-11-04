#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7, pow_mod[1024] = {1};

static inline int decimal_value(char c) { return c - 'A'; }

int main(void) {
	ios_base::sync_with_stdio(false);

	for(int i = 1; i <= 1000; ++i) {
		pow_mod[i] = (26 * (long long) pow_mod[i - 1] % mod) % mod;
	}

	string A;
	while(cin >> A) {
		int ans = 0;
		for(int i = 0, n = A.length() - 1; A[i]; ++i) {
			ans = (ans % mod + (decimal_value(A[i]) * (long long) pow_mod[n - i]) % mod) % mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}
