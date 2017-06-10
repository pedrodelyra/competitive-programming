#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

int main() {
        lld n;
        scanf("%lld", &n);
        lld l = 1, r = n, sqroot = 0;
        while(l <= r and sqroot == 0) {
                lld m = l + r >> 1;
                if(m * m == n) {
                        sqroot = m;
                } else if(m * m < n) {
                        l = m + 1;
                } else {
                        r = m - 1;
                }
        }
        if(sqroot) {
                printf("Square root of %lld equals %lld\n", n, sqroot);
        } else {
                printf("%lld does not have a square root\n", n);
        }
        return 0;
}
