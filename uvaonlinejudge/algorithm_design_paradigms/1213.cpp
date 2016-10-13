#include <bits/stdc++.h>

#define MAX 1125
#define MAX_PRIMES 200
#define MAX_K 15

using namespace std;
using ll = long long int;

int n, k, primes[MAX_PRIMES], num_primes;
ll dp[MAX][MAX_PRIMES][MAX_K];

ll num_ways(int sum, int i, int j) {
        if(sum < 0 || i == num_primes || j > k) {
                return 0;
        } else if(sum == 0 && j == k) {
                return 1;
        } else if(~dp[sum][i][j]) {
                return dp[sum][i][j];
        }

        return dp[sum][i][j] = num_ways(sum - primes[i], i + 1, j + 1) + num_ways(sum, i + 1, j);
}

int main(void) {
        for(int i = 2; i <= MAX; ++i) {
                int count = 0;
                for(int j = 2; j <= sqrt(i); ++j) {
                        count += i % j == 0;
                }

                if(count == 0) primes[num_primes++] = i;
        }

        while(scanf("%d %d", &n, &k), n | k) {
                memset(dp, -1, sizeof dp);
                printf("%lld\n", num_ways(n, 0, 0));
        }

        return 0;
}
