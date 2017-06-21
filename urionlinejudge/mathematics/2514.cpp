#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
        return a * b / gcd(a, b);
}

int lcm(int a, int b, int c) {
        return lcm(a, lcm(b, c));
}

int main() {
        int m, x, y, z;
        while(cin >> m >> x >> y >> z) {
                cout << lcm(x, y, z) - m << endl;
        }
        return 0;
}
