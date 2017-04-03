#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

const lld oo = 10000000000L;

vector<lld> lucky_numbers;

void generate_nums(lld n) {
        if(n <= oo) {
                lucky_numbers.push_back(n);
                generate_nums(n * 10 + 4);
                generate_nums(n * 10 + 7);
        }
}

int main() {
        lld l, r, ans = 0;
        cin >> l >> r;
        generate_nums(0);
        sort(lucky_numbers.begin(), lucky_numbers.end());
        int i = 1;
        while(l <= r) {
                while(lucky_numbers[i] < l) ++i;
                ans += (min(r, lucky_numbers[i]) - l + 1) * lucky_numbers[i];
                l = lucky_numbers[i] + 1;
        }
        cout << ans << endl;
        return 0;
}
