#include <bits/stdc++.h>

#define MAX 200005

using namespace std;
using llu = unsigned long long int;

llu a[MAX], b[MAX], c[MAX], d[MAX];

int main(void) {
        llu n, x, s;
        int m, k;
        scanf("%llu %d %d", &n, &m, &k);
        scanf("%llu %llu", &x, &s);

        llu ans = n * x;
        for(int i = 0; i < m; ++i) {
                scanf("%llu", &a[i]);
        }

        for(int i = 0; i < m; ++i) {
                scanf("%llu", &b[i]);
                if(b[i] <= s) {
                        ans = min(ans, n * a[i]);
                }
        }

        for(int i = 0; i < k; ++i) {
                scanf("%llu", &c[i]);
        }

        for(int i = 0; i < k; ++i) {
                scanf("%llu", &d[i]);
                if(d[i] <= s) {
                        ans = min(ans, (n - c[i]) * x);
                }
        }

        for(int i = 0; i < m; ++i) {
                int idx = -1, l = 0, r = k - 1;
                while(l <= r) {
                        int m = (l + r) >> 1;
                        if(d[m] + b[i] <= s) {
                                idx = m;
                                l = m + 1;
                        } else {
                                r = m - 1;
                        }
                }
                if(~idx) {
                        ans = min(ans, (n - c[idx]) * a[i]);
                }
        }
        printf("%llu\n", ans);
	return 0;
}
