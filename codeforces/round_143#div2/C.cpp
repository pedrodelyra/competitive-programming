#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

const lld oo = 1LL << 50;

int main() {
        int n;
        lld k;
        cin >> n >> k;
        vector<lld> a(n + 1), s(n + 1, 0);
        for(int i = 1; i <= n; ++i) {
                cin >> a[i];
        }
        sort(a.begin() + 1, a.end());
        for(int i = 1; i <= n; ++i) {
                s[i] = s[i - 1] + a[i];
        }
        lld max_occur = 0, min_value;
        for(lld i = 1; i <= n; ++i) {
                lld l = i, r = n;
                while(l <= r) {
                        lld m = l + r >> 1;
                        lld cost = a[m] * (m - i + 1) - (s[m] - s[i - 1]);
                        if(cost <= k) {
                                if(m - i + 1 >= max_occur) {
                                        min_value = m - i + 1 > max_occur ? a[m] : min(min_value, a[m]);
                                        max_occur = m - i + 1;
                                }
                                l = m + 1;
                        } else {
                                r = m - 1;
                        }
                }
        }
        cout << max_occur << " " << min_value << endl;
        return 0;
}
