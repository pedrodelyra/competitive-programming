#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX = 128;

char grid[MAX][MAX];
bool has_cycle = false, visited[MAX][MAX];
ii   movements[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}, parents[MAX][MAX];

void dfs(int x, int y) {
        visited[x][y] = true;
        for(auto& move : movements) {
                int dx = move.first, dy = move.second;
                if(grid[x][y] != grid[x + dx][y + dy]) {
                       continue;
                } else if(not visited[x + dx][y + dy]) {
                        parents[x + dx][y + dy] = ii(x, y);
                        dfs(x + dx, y + dy);
                } else if(parents[x][y] != ii(x + dx, y + dy)) {
                        has_cycle = true; break;
                }
        }
}

int main() {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) {
                        cin >> grid[i][j];
                }
        }
        for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) {
                        if(not visited[i][j]) {
                                dfs(i, j);
                        }
                }
        }
        cout << (has_cycle ? "Yes" : "No") << endl;
        return 0;
}
