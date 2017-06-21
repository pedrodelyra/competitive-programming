#include <bits/stdc++.h>

using namespace std;

int main() {
        ios_base::sync_with_stdio(false);
        int tc;
        cin >> tc;
        while(tc--) {
                int n;
                cin >> n;
                vector<int> a(n);
                for(int i = 0; i < n; ++i)
                        cin >> a[i];
                sort(a.begin(), a.end());
                for(int i = 0; i < n; ++i) {
                        cout << a[i] << " \n"[i + 1 == n];
                }
        }
        return 0;
}
