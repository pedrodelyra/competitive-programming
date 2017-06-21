#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

vector<lld> dp(48, -1);

lld fib(int n) {
        if(n <= 1) {
                return 1;
        } else if(~dp[n]) {
                return dp[n];
        } else {
                return dp[n] = fib(n - 1) + fib(n - 2);
        }
}

int main() {
        int n;
        while(cin >> n, n) {
                cout << fib(n) << endl;
        }
        return 0;
}
