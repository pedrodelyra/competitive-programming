#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

const int max_prime = 1e6;

vector<bool> prime(max_prime + 5);
set<lld> s;

void sieve() {
        fill(prime.begin() + 2, prime.end(), true);
        for(lld i = 2; i <= max_prime; ++i) {
                if(prime[i]) {
                        for(lld j = i << 1; j <= max_prime; j += i) {
                                prime[j] = false;
                        }
                        s.insert(i * i);
                }
        }
}

int main() {
        int n; cin >> n; sieve();
        for(int i = 1; i <= n; ++i) {
                lld x;
                cin >> x;
                cout << (s.count(x) ? "YES" : "NO") << endl;
        }
        return 0;
}
