#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX = 512;

vector<ii> movements = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char grid[MAX][MAX];
bool visited[MAX][MAX];
int  counter;

void dfs(int x, int y) {
        visited[x][y] = true;
        --counter;
        for(auto& move : movements) {
                int dx = move.first, dy = move.second;
                if(grid[x + dx][y + dy] == '.' and not visited[x + dx][y + dy] and counter) {
                        dfs(x + dx, y + dy);
                }
        }
}

int main() {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        memset(grid, '#', sizeof grid);
        int x, y, t = 0;
        for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) {
                        scanf(" %c", &grid[i][j]);
                        if(grid[i][j] == '.') {
                                x = i;
                                y = j;
                                ++t;
                        }
                }
        }
        counter = t - k;
        dfs(x, y);
        for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) {
                        printf("%c", grid[i][j] == '.' and not visited[i][j] ? 'X' : grid[i][j]);
                }
                printf("\n");
        }
        return 0;
}
