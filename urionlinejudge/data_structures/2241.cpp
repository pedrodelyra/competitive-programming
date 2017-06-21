#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

const int BLACK = 1, WHITE = 2;

int main() {
        int n, m;
        cin >> n >> m;
        int a[n + 1][n + 1]; memset(a, 0, sizeof a);
        for(int i = 1; i <= m; ++i) {
                int x, y;
                cin >> x >> y;
                a[x][y] = BLACK;
        }
        for(int i = 1; i <= m; ++i) {
                int x, y;
                cin >> x >> y;
                a[x][y] = WHITE;
        }
        lld b[n + 1][n + 1], w[n + 1][n + 1];
        memset(b, 0, sizeof b); memset(w, 0, sizeof w);
        for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                        b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + (a[i][j] == BLACK);
                        w[i][j] = w[i - 1][j] + w[i][j - 1] - w[i - 1][j - 1] + (a[i][j] == WHITE);
                }
        }
        lld blacks = 0, whites = 0;
        for(int s = 0; s < n; ++s) {
                for(int i = 1; i + s <= n; ++i) {
                        for(int j = 1; j + s <= n; ++j) {
                                int num_blacks = b[i + s][j + s] - b[i - 1][j + s] - b[i + s][j - 1] + b[i - 1][j - 1];
                                int num_whites = w[i + s][j + s] - w[i - 1][j + s] - w[i + s][j - 1] + w[i - 1][j - 1];
                                if(num_blacks and num_whites == 0)
                                        ++blacks;
                                if(num_whites and num_blacks == 0)
                                        ++whites;
                        }
                }
        }
        cout << blacks << " " << whites << endl;
        return 0;
}
