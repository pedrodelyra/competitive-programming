#include <bits/stdc++.h>

using namespace std;

int main() {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
                cin >> a[i];
        }
        sort(a.begin(), a.end(), [] (const int& a, const int& b) {
                return (a & 1) ? (b & 1 ? a > b : false) : (b & 1 ? true : a < b);
        });
        for(int i = 0; i < n; ++i) {
                cout << a[i] << endl;
        }
        return 0;
}
