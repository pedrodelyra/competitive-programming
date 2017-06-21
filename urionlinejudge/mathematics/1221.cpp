#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

bool is_prime(lld n) {
        for(int i = 2; i * i <= n; ++i) {
                if(n % i == 0) {
                        return false;
                }
        }
        return n != 1;
}

int main() {
        int tc;
        cin >> tc;
        while(tc--) {
                lld n;
                cin >> n;
                cout << (is_prime(n) ? "Prime" : "Not Prime") << endl;
        }
        return 0;
}
