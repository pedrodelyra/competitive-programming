#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

int main() {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
                cin >> a[i];
        }
        sort(a.begin(), a.end());
        lld moves = 0;
        for(int i = 0; i < n; ++i) {
                moves += abs(1LL + i - a[i]);
        }
        cout << moves << endl;
        return 0;
}
