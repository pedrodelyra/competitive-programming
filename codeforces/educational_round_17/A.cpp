#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

int main() {
        lld n, k;
        cin >> n >> k;
        vector<lld> divisors;
        for(lld i = 1; i * i <= n; ++i) {
                if(n % i == 0) {
                        divisors.push_back(i);
                        if(n / i != i)
                                divisors.push_back(n / i);
                }
        }
        sort(begin(divisors), end(divisors));
        cout << (k <= divisors.size() ? divisors[k - 1] : -1) << endl;
        return 0;
}
