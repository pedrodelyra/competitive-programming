#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

const int mod = 1e9 + 7;

lld pow_mod(lld x, lld n) {
        lld p = 1;
        for(int i = 1; i <= n; ++i)
                p = (p * x) % mod;
        return p;
}

int main() {
        lld a, b, n;
        cin >> a >> b >> n;
        vector<int> div(b + 1, 0);
        for(int i = 1; i <= b; ++i) {
                for(int j = i; j <= b; j += i)
                        div[j]++;
        }
        int l = 0;
        for(int i = a; i <= b; ++i) {
                if(div[i] == n)
                        ++l;
        }
        cout << pow_mod(l, b - a + 1 - l) << endl;
        return 0;
}
