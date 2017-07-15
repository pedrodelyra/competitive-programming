#include <bits/stdc++.h>

#define MAX 256

using namespace std;
using ii = pair<int, int>;

int  k, grid[MAX][MAX];
bool visited[MAX][MAX];
vector<ii> movements = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int x, int y) {
        visited[x][y] = true;
        for(auto& move : movements) {
                int dx = move.first, dy = move.second;
                if(grid[x + dx][y + dy] == grid[x][y] and not visited[x + dx][y + dy]) {
                        dfs(x + dx, y + dy);
                }
        }
        ++k;
}

int main() {
        int n, m;
        cin >> n >> m;
        memset(grid, -1, sizeof grid);
        for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j)
                        cin >> grid[i][j];
        }
        int ans = n * m;
        for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) {
                        if(not visited[i][j]) {
                                k = 0, dfs(i, j);
                                ans = min(ans, k);
                        }
                }
        }
        cout << ans << endl;
        return 0;
}
