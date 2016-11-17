#include <bits/stdc++.h>

using namespace std;

int main(void) {
        int n, m, k, count = 0;
        scanf("%d %d %d", &n, &m, &k);
        for(int i = 1, x = 0; i <= m; ++i) {
                int dx;
                scanf("%d", &dx);
                x = (n + x + dx) % n;
                count += x + 1 == k;
        }
        printf("%d\n", count + (k == 1));
        return 0;
}
