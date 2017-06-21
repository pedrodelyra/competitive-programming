#include <bits/stdc++.h>

using namespace std;
using lld = long long;

int main() {
        lld n, m;
        while(cin >> n >> m, n and m) {
                lld x = 0;
                for(lld i = 1; i * i <= n; ++i) {
                        if(n % i == 0)
                                x += i + (i > 1 && i * i < n ? n / i : 0);
                }
                lld y = 0;
                for(lld i = 1; i * i <= m; ++i) {
                        if(m % i == 0)
                                y += i + (i > 1 && i * i < m ? m / i : 0);
                }
                if(n % y == 0 and m % x == 0) {
                        cout << "Friends and lovers <3" << endl;
                } else if(x == y) {
                        cout << "Almost lovers!" << endl;
                } else if(n % y == 0) {
                        cout << n << " friendzoned " << m << "!" << endl;
                } else if(m % x == 0) {
                        cout << m << " friendzoned " << n << "!" << endl;
                } else {
                        cout << "No connection." << endl;
                }
        }
        return 0;
}
