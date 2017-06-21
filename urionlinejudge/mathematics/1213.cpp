#include <bits/stdc++.h>

using namespace std;

int main() {
        int n;
        while(~scanf("%d", &n)) {
                int m = 1, count = 1;
                while(m % n) m = (10 * m + 1) % n, ++count;
                printf("%d\n", count);
        }
        return 0;
}
