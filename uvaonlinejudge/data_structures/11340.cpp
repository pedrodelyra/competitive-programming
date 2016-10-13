#include <cstdio>
#include <cstring>

int payments[512];

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int k;
		scanf("%d\n", &k);
		memset(payments, 0, sizeof payments);
		for(int i = 0; i < k; ++i) {
			char c;
			int cents;
			scanf("%c %d\n", &c, &cents);
			payments[c] = cents;
		}

		int n, total = 0;
		scanf("%d\n", &n);
		while(n) {
			unsigned char c;
			c = getchar_unlocked();
			total += payments[c];

			if(c == '\n') --n;
		}

		printf("%d.%02d$\n", total / 100, total % 100); 
	}

	return 0;
}
