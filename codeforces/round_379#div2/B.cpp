#include <bits/stdc++.h>

using namespace std;

int main(void) {
        int k2, k3, k5, k6;
        scanf("%d %d %d %d", &k2, &k3, &k5, &k6);
        int a = min(k2, min(k5, k6));
        int b = min(k3, k2 - a);
        printf("%d\n", 256 * a + 32 * b);
	return 0;
}
