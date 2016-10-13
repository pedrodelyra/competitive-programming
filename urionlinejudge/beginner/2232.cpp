#include <bits/stdc++.h>

int main(void) {
	int tc, pot = 2, S[32] = {1};
	scanf("%d", &tc);

	for(int i = 1; i < 32; ++i, pot <<= 1) {
		S[i] = S[i - 1] + pot;
	}

	while(tc--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", S[n - 1]);
	}

	return 0;
}
