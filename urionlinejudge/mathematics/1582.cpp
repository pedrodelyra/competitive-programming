#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

lld gcd(lld a, lld b) {
        return b == 0 ? a : gcd(b, a % b);
}

lld gcd(lld a, lld b, lld c) {
        return gcd(a, gcd(b, c));
}

int main() {
        lld x, y, z;
        while(cin >> x >> y >> z) {
                if(x * x == y * y + z * z or
                   y * y == x * x + z * z or
                   z * z == x * x + y * y) {
                        cout << (gcd(x, y, z) == 1 ? "tripla pitagorica primitiva" :
                                                     "tripla pitagorica") << endl;
                } else {
                        cout << "tripla" << endl;
                }
        }
        return 0;
}
