#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e6, MAX_K = 12;

auto is_prime = bitset<MAX_N + 5>{};
int  s[MAX_N + 1][MAX_K + 1];

void sieve(int n) {
        vector<int> divisors(n + 1, 0);
        for(int i = 1; i <= n; ++i)
                for(int j = i; j <= n; j += i)
                        divisors[j]++;
        for(int i = 1; i <= n; ++i)
                if(divisors[i] == 2) is_prime[i] = true;
}

int count_rounds(int n) {
        if(is_prime[n]) {
                return 1;
        } else {
                int s = 0;
                for(int i = 2; i * i <= n; ++i) {
                        if(n % i == 0)    s += i;
                        while(n % i == 0) n /= i;
                }
                return count_rounds(s + (n > 1 ? n : 0)) + 1;
        }
}

int main() {
        ios_base::sync_with_stdio(false), sieve(MAX_N);
        vector<int> rounds(MAX_N + 1);
        for(int i = 2; i <= MAX_N; ++i)
                rounds[i] = count_rounds(i);

        for(int i = 1; i <= MAX_N; ++i)
                for(int k = 1; k <= MAX_K; ++k)
                        s[i][k] = s[i - 1][k] + (rounds[i] == k);
        int tc;
        cin >> tc;
        while(tc--) {
                int a, b, k;
                cin >> a >> b >> k;
                cout << (k <= MAX_K ? s[b][k] - s[a - 1][k] : 0) << endl;
        }
        return 0;
}
