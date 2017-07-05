#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

lld dp[64][64];

bool is_prime(int n) {
        for(int i = 2; i * i <= n; ++i)
                if(n % i == 0)
                        return false;
        return n >= 2;
}

lld binomial(int n, int k) {
        if(n == k or k == 0) {
                return 1;
        } else if(dp[n][k]) {
                return dp[n][k];
        } else {
                return dp[n][k] = binomial(n - 1, k - 1) + binomial(n - 1, k);
        }
}

int main() {
        int n, m, k;
        while(cin >> n >> m >> k, n | m | k) {
                vector<int> rows(n, 0), cols(m, 0);
                for(int i = 0; i < n; ++i) {
                        for(int j = 0; j < m; ++j) {
                                rows[i] += is_prime(m * i + j);
                                cols[j] += is_prime(m * i + j);
                        }
                }
                lld count = 0;
                for(int i = 0; i < n; ++i) {
                        int r = m - rows[i];
                        if(r >= k) count += binomial(r, k);
                }
                for(int i = 0; i < m; ++i) {
                        int r = n - cols[i];
                        if(r >= k) count += binomial(r, k);
                }
                cout << (k > 1 ? count : count >> 1) << endl;
        }
        return 0;
}
