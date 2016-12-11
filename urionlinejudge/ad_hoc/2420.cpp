#include <bits/stdc++.h>

using namespace std;

int sum[100005];

int main(void) {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		sum[i] = sum[i - 1] + x;
	}
	int idx = -1;
	for(int i = 1; !~idx and i <= n; ++i) {
		if(2 * sum[i] == sum[n]) {
			idx = i;
		}
	}
	printf("%d\n", idx);
	return 0;
}
