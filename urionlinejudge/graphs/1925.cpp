#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

char grid[1024][1024];
int  color[1024][1024], ccs[1000005];
set<int> neighbours[1024][1024];
vector<ii> movements = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int x, int y, int k, int& count) {
        color[x][y] = k;
        for(auto& move : movements) {
                int dx = move.first, dy = move.second;
                if(grid[x + dx][y + dy] == 'n' and color[x + dx][y + dy] == 0) {
                        dfs(x + dx, y + dy, k, count);
                } else if(grid[x + dx][y + dy] == '*') {
                        neighbours[x + dx][y + dy].insert(k);
                }
        }
        ++count;
}

int main() {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= m; ++j)
                        scanf(" %c", &grid[i][j]);
        int k = 1;
        for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) {
                        if(grid[i][j] == 'n' and color[i][j] == 0) {
                                int count = 0;
                                dfs(i, j, k, count);
                                ccs[k++] = count;
                        }
                }
        }
        int x, y, max_count = 0;
        for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) {
                        if(grid[i][j] == '*') {
                                int count = 0;
                                for(auto& x : neighbours[i][j]) {
                                        count += ccs[x];
                                }
                                if(count > max_count)
                                        max_count = count, x = i, y = j;
                        }
                }
        }
        printf("%d,%d\n", x, y);
        return 0;
}
