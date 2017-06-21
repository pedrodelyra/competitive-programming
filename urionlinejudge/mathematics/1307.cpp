#include <bits/stdc++.h>

using namespace std;
using lld = long long;

lld gcd(lld a, lld b) {
        return b == 0 ? a : gcd(b, a % b);
}

int main() {
        int tests;
        cin >> tests;
        for(int tc = 1; tc <= tests; ++tc) {
                string a, b;
                cin >> a >> b;
                lld s = 0, t = 0;
                for(char c : a)
                        s = s << 1 | (c - '0');
                for(char c : b)
                        t = t << 1 | (c - '0');
                cout << "Pair #" << tc << ": " << (gcd(s, t) > 1 ? "All you need is love!" : "Love is not all you need!") << endl;
        }
        return 0;
}
