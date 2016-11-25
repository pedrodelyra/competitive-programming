#include <bits/stdc++.h>

using namespace std;

int A[128], sum[128], f[128];

int main(void) {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; ++i) {
                scanf("%d", &A[i]);
        }
        for(int i = 1; i <= m; ++i) {
                int l, r;
                scanf("%d %d", &l, &r);
                for(int j = l; j <= r; ++j) {
                        sum[i] += A[j];
                }
                if(sum[i] > 0) {
                        for(int j = l; j <= r; ++j) {
                                f[j]++;
                        }
                }
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
                if(f[i]) {
                        ans += f[i] * A[i];
                }
        }
        printf("%d\n", ans);

	return 0;
}
