#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

const int MAX_N = 3e6 + 5;

vector<lld> p;

void sieve() {
        auto is_prime = bitset<MAX_N>{}.set();
        for(lld i = 3; i <= MAX_N; i += 2) {
                if(is_prime[i]) {
                        for(lld j = i * i; j <= MAX_N; j += i) {
                                is_prime[i] = false;
                        }
                        p.push_back(i);
                }
        }
}

int main() {
        lld n; sieve();
        while(~scanf("%lld", &n)) {
                lld num_ways = 1;
                while(n % 2 == 0) n >>= 1;
                for(int i = 0; p[i] * p[i] <= n and i < p.size(); ++i) {
                        int alpha = 0;
                        while(n % p[i] == 0) {
                                n /= p[i];
                                ++alpha;
                        }
                        num_ways *= (1 + alpha);
                }
                if(n > 1) num_ways <<= 1;
                printf("%lld\n", num_ways);
        }
        return 0;
}
