#include <bits/stdc++.h>

using namespace std;

int main() {
        int n, m;
        cin >> n >> m;
        int a[n + 1][m + 1];
        for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) {
                        cin >> a[i][j];
                }
        }
        int s[n + 1][m + 1]; memset(s, 0, sizeof s);
        for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) {
                        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (a[i][j] == 0);
                }
        }
        int q;
        cin >> q;
        while(q--) {
                int x;
                cin >> x; --x;
                bool ans = false;
                for(int i = 1; i + x <= n; ++i) {
                        for(int j = 1; j + x <= m; ++j) {
                                if(s[i + x][j + x] + s[i - 1][j - 1] - s[i + x][j - 1] - s[i - 1][j + x] == 0)
                                        ans = true;
                        }
                }
                cout << (ans ? "yes" : "no") << endl;
        }
        return 0;
}
