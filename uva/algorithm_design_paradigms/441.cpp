#include <bits/stdc++.h>

int main(void) {
	int n, S[15], tc = 0;
	while(scanf("%d", &n), n) {
		for(int i = 0; i < n; ++i) {
			scanf("%d", &S[i]);
		}

		if(tc++) { printf("\n"); }
		for(int a = 0; a < n - 5; ++a) {
			for(int b = a + 1; b < n - 4; ++b) {
				for(int c = b + 1; c < n - 3; ++c) {
					for(int d = c + 1; d < n - 2; ++d) {
						for(int e = d + 1; e < n - 1; ++e) {
							for(int f = e + 1; f < n; ++f) {
								printf("%d %d %d %d %d %d\n", S[a], S[b], S[c], S[d], S[e], S[f]);
							}
						}
					}
				}
			}
		}
	}

	return 0;
}
