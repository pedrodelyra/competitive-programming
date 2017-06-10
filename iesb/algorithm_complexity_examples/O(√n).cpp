#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

// test 950973649649

bool is_prime(lld n) {
        for(lld i = 2; i * i <= n; ++i) {
                if(n % i == 0) return false;
        }
        return n != 1;
}

int main() {
        lld n;
        scanf("%lld", &n);
        printf(is_prime(n) ? "%lld is prime\n" : "%lld isn't prime\n", n);
        return 0;
}
