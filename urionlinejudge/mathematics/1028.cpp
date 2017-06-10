#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
        return a == 0 ? b : gcd(b % a, a);
}

int main() {
        int tc;
        cin >> tc;
        while(tc--) {
                int x, y;
                cin >> x >> y;
                cout << gcd(x, y) << endl;
        }
        return 0;
}
