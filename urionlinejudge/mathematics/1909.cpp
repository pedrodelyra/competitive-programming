#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
        return a / gcd(a, b) * b;
}

int main() {
        int n, t;
        while(cin >> n >> t, n and t) {
                int l = 1; set<int> s;
                for(int i = 1; i <= n; ++i) {
                        int x;
                        cin >> x;
                        l = lcm(l, x);
                        s.insert(x);
                }
                int q = -1;
                for(int i = 2; !~q and i <= t; ++i)
                        if(s.count(i) == 0 && lcm(l, i) == t)
                                q = i;

                if(~q) {
                        cout << q << endl;
                } else {
                        cout << "impossivel" << endl;
                }
        }
        return 0;
}
