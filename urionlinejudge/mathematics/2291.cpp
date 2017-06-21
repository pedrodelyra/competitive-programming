#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

const int MAX_N = 1e6 + 5;

int main() {
        vector<lld> d(MAX_N, 0);
        for(lld i = 1; i <= MAX_N; ++i) {
                for(lld j = i; j <= MAX_N; j += i) {
                        d[j] += i;
                }
        }
        vector<lld> s(MAX_N, 0);
        for(int i = 1; i <= MAX_N; ++i)
                s[i] = s[i - 1] + d[i];
        lld n;
        while(cin >> n, n) {
                cout << s[n] << endl;
        }
        return 0;
}
