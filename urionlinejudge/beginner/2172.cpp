#include <cstdio>

int main(void) {
	long long int x, y;
	while(scanf("%lld %lld", &x, &y), x | y) {
		printf("%lld\n", x * y);
	}

	return 0;
}
