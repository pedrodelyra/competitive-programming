#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

int  grid[8][8];
bool visited[8][8];
vector<ii> movements = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int x, int y) {
        visited[x][y] = true;
        for(auto& move : movements) {
                int dx = move.first, dy = move.second;
                if(!grid[x + dx][y + dy] and !visited[x + dx][y + dy]) {
                        dfs(x + dx, y + dy);
                }
        }
}

int main() {
        int tc, n = 5;
        cin >> tc;
        while(tc--) {
                memset(grid, 1, sizeof grid);
                for(int i = 1; i <= n; ++i) {
                        for(int j = 1; j <= n; ++j) {
                                cin >> grid[i][j];
                        }
                }
                memset(visited, false, sizeof visited);
                dfs(1, 1);
                cout << (visited[5][5] ? "COPS" : "ROBBERS") << endl;
        }
        return 0;
}
