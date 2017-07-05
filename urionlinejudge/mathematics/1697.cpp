#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e7;

vector<int> p = {1};

void sieve() {
        auto is_prime = bitset<MAX_N + 5> {}.set();
        for(int i = 2; i <= MAX_N; ++i) {
                if(is_prime[i]) {
                        for(int j = i + i; j <= MAX_N; j += i)
                                is_prime[j] = false;
                        p.push_back(i);
                }
        }
}

int main() {
        int tc;
        scanf("%d", &tc);
        sieve();
        while(tc--) {
                int n;
                scanf("%d", &n);
                set<int> s;
                for(int i = 1; i <= n; ++i) {
                        int x;
                        cin >> x;
                        s.insert(x);
                }
                int k = -1;
                for(int i = 0; !~k and i < p.size(); ++i)
                        if(s.count(p[i]) == 0)
                                k = i;
                printf("%d\n", p[k] - 1);
        }
        return 0;
}
