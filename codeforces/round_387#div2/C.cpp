#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

lld servers[128];

int main(void) {
	int n, q;
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i) servers[i] = 1;
	while(q--) {
		int t, k, d;
		scanf("%d %d %d", &t, &k, &d);
		int cnt = 0, sum = 0;
		for(int i = 1; cnt < k and i <= n; ++i) {
			if(servers[i] <= t) {
				cnt++;
			}
		}
		if(cnt == k) {
			for(int i = 1; cnt and i <= n; ++i) {
				if(servers[i] <= t) {
					servers[i] = t + d;
					sum += i;
					cnt--;
				}
			}
			printf("%d\n", sum);
		} else {
			printf("-1\n");
		}
	}
	return 0;
}
