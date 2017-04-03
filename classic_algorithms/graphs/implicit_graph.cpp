#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int oo = 0x3f3f3f3f;

char grid[1024][1024]; // grid seen as implicit graph: '.' means free cell and '#' means wall
vector<ii> movements = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool visited[1024][1024];
int  dist[1024][1024];

void dfs(int x, int y) {
        visited[x][y] = true;
        for(auto& move : movements) {
                int dx = move.first, dy = move.second;
                if(grid[x + dx][y + dy] == '.' and not visited[x + dx][y + dy]) {
                        dfs(x + dx, y + dy);
                }
        }
}

void bfs(int x0, int y0) {
        queue<ii> q;
        memset(dist, oo, sizeof dist);
        dist[x0][y0] = 0;
        q.push(ii(x0, y0));
        while(not q.empty()) {
                auto current_pos = q.front(); q.pop();
                auto x = current_pos.first, y = current_pos.second;
                for(auto& move : movements) {
                        int dx = move.first, dy = move.second;
                        if(grid[x + dx][y + dy] == '.' and dist[x + dx][y + dy] == oo) {
                                dist[x + dx][y + dy] = dist[x][y] + 1;
                                q.push(ii(x + dx, y + dy));
                        }
                }
        }
}

int main() {
        int n, m;
        cin >> n >> m;
        memset(grid, '#', sizeof grid);
        for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) {
                        cin >> grid[i][j];
                }
        }
        for(int x = 1; x <= n; ++x) {
                for(int y = 1; y <= m; ++y) {
                        if(grid[x][y] == '.' and not visited[x][y]) {
                                dfs(x, y);
                        }
                }
        }
        for(int x = 1; x <= n; ++x) {
                for(int y = 1; y <= m; ++y) {
                        if(grid[x][y] == '.' and dist[x][y] == oo) {
                                dfs(x, y);
                        }
                }
        }
        return 0;
}
