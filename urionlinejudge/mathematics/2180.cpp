#include <bits/stdc++.h>

using namespace std;

const long long dist = 60e6;

bool is_prime(int n) {
        for(int i = 2; i * i <= n; ++i)
                if(n % i == 0)
                        return false;
        return n != 1;
}

int main() {
        int n;
        cin >> n;
        int v = 0;
        for(int i = n, count = 0; count < 10; ++i) {
                if(is_prime(i)) {
                        ++count, v += i;
                }
        }
        cout << v << " km/h" << endl;
        cout << dist / v << " h / " << dist / (24 * v) << " d" << endl;
        return 0;
}
