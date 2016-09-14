#include <bits/stdc++.h>

using namespace std;

int bit_index(int n) {
	int count = -1;
	while(n) {
		n >>= 1;
		++count;
	}

	return count;
}

int main(void) {
	int n;
	while(scanf("%d", &n), n) {
		int a, b, k;
		a = b = k = 0;
		while(n) {
			int first_set = n & -n;
			int index = bit_index(first_set);

			if(k & 1) {
				b |= 1 << index;
			} else {
				a |= 1 << index;
			}

			n &= ~first_set;
			k = !k;
		}

		printf("%d %d\n", a, b);
	}

	return 0;
}
