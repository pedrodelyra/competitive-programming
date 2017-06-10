#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

lld f(int n) {
        return n == 0 ? 1LL : n * f(n - 1);
}

int main() {
        int x, y;
        while(cin >> x >> y) {
                cout << f(x) + f(y) << endl;
        }
        return 0;
}
