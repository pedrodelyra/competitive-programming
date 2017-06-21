#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

const int MAX_N = 1e6 + 5;

int main() {
        int tc;
        cin >> tc;
        auto is_prime = bitset<MAX_N>{}.set(), twin = bitset<MAX_N>{};
        for(lld i = 3, j = 2; i <= MAX_N; i += 2) {
                if(is_prime[i]) {
                        for(lld k = i * i; k <= MAX_N; k += i) {
                                is_prime[k] = false;
                        }
                        if(i - j == 2)
                                twin[i] = twin[j] = true;
                        j = i;
                }
        }
        vector<int> s(MAX_N, 0);
        for(int i = 1; i < MAX_N; ++i)
                s[i] = s[i - 1] + twin[i];

        while(tc--) {
                int x, y;
                cin >> x >> y;
                cout << s[max(x, y)] - s[min(x, y) - 1] << endl;
        }
        return 0;
}
