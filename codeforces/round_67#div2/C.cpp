#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

int main() {
        lld a, b;
        cin >> a >> b;
        set<lld> a_divisors;
        for(lld i = 1; i * i <= a; ++i) {
                if(a % i == 0) {
                        a_divisors.insert(i);
                        a_divisors.insert(a / i);
                }
        }
        set<lld> b_divisors;
        for(lld i = 1; i * i <= b; ++i) {
                if(b % i == 0) {
                        b_divisors.insert(i);
                        b_divisors.insert(b / i);
                }
        }
        vector<lld> common_divisors;
        set_intersection(a_divisors.begin(), a_divisors.end(),
                         b_divisors.begin(), b_divisors.end(),
                         back_inserter(common_divisors));
        int q;
        cin >> q;
        while(q--) {
                lld l, r;
                cin >> l >> r;
                auto it = lower_bound(common_divisors.begin(), common_divisors.end(), r);
                if(*it > r or it == common_divisors.end()) it--;
                cout << (*it >= l ? *it : -1) << endl;
        }
        return 0;
}
