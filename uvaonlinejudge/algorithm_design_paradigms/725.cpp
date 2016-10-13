#include <bits/stdc++.h>

int main(void) {
	int n, tc = 0;
	while(scanf("%d", &n), n) {
		bool possible = false;

		if(tc++) printf("\n");

		for(int fghij = 1234; fghij <= 98765 / n; ++fghij) {
			int abcde = fghij * n;
			int mask = fghij < 10000, tmp;

			tmp = fghij;
			while(tmp) {
				mask |= 1 << (tmp % 10);
				tmp /= 10;
			}

			tmp = abcde;
			while(tmp) {
				mask |= 1 << (tmp % 10);
				tmp /= 10;
			}

			if(mask == (1 << 10) - 1) {
				possible = true;
				printf("%05d / %05d = %d\n", abcde, fghij, n);
			}
		}

		if(not possible) {
			printf("There are no solutions for %d.\n", n);
		}
	}

	return 0;
}
