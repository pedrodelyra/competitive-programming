#include <bits/stdc++.h>

#define MAX 1030

using namespace std;
using ii = pair<int, int>;

char grid[MAX][MAX];
bool visited[MAX][MAX];
vector<ii> movements = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int x, int y) {
        visited[x][y] = true;
        for(auto& move : movements) {
                int dx = move.first, dy = move.second;
                if(grid[x + dx][y + dy] == '.' and not visited[x + dx][y + dy]) {
                        dfs(x + dx, y + dy);
                }
        }
}

int main() {
        int n, m;
        cin >> n >> m;
        memset(grid, 'o', sizeof grid);
        for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) {
                        cin >> grid[i][j];
                }
        }
        int count = 0;
        for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) {
                        if(grid[i][j] == '.' and not visited[i][j]) {
                                dfs(i, j);
                                ++count;
                        }
                }
        }
        cout << count << endl;
        return 0;
}
