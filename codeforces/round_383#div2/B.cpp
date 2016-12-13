#include <cstdio>

#define MAX 200005

int f[MAX];

int main(void) {
	int n, x;
	scanf("%d %d", &n, &x);
	long long ans = 0;
	for(int i = 1, k; i <= n; ++i) {
		scanf("%d", &k);
		ans += f[k ^ x];
		f[k]++;
	}
	printf("%lld\n", ans);
	return 0;
}
