#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX = 128;

vector<ii> movements = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char grid[MAX][MAX];
bool visited[MAX][MAX];

void dfs(int x, int y, bool state = true) {
        visited[x][y] = true;
        for(auto& move : movements) {
                int dx = move.first, dy = move.second;
                if(grid[x + dx][y + dy] == '.' and not visited[x + dx][y + dy]) {
                        dfs(x + dx, y + dy, !state);
                }
        }
        grid[x][y] = state ? 'B' : 'W';
}

int main() {
        int n, m;
        scanf("%d %d", &n, &m);
        memset(grid, '-', sizeof grid);
        for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) {
                        scanf(" %c", &grid[i][j]);
                }
        }
        for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) {
                        if(grid[i][j] == '.' and not visited[i][j]) {
                                dfs(i, j);
                        }
                }
        }
        for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) {
                        printf("%c", grid[i][j]);
                }
                printf("\n");
        }
        return 0;
}
