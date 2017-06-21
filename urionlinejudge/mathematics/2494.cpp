#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
}

int main() {
        int n, m, k;
        while(cin >> n >> m >> k) {
                int d = gcd(n, m);
                cout << ((n / d + m / d) >= k ? "sim" : "nao") << endl;
        }
        return 0;
}
