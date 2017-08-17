#include <bits/stdc++.h>

using namespace std;
using vii = vector<pair<int, int>>;

char grid[512][512];
int  fx, fy, max_dist, dist[512][512];
vii  moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int x, int y, int d = 0) {
        dist[x][y] = d;
        for(auto& m : moves) {
                int dx = m.first, dy = m.second;
                if(grid[x + dx][y + dy] != '#' and !~dist[x + dx][y + dy]) {
                        dfs(x + dx, y + dy, d + 1);
                }
        }
        if(d > max_dist) max_dist = d, fx = x, fy = y;
}

int main() {
        int n, m;
        while(cin >> n >> m, n | m) {
                int x0, y0;
                memset(grid, '#', sizeof grid);
                for(int i = 1; i <= n; ++i) {
                        for(int j = 1; j <= m; ++j) {
                                cin >> grid[i][j];
                                if(grid[i][j] == '.') x0 = i, y0 = j;
                        }
                }
                max_dist = 0;
                memset(dist, -1, sizeof dist), dfs(x0, y0);
                memset(dist, -1, sizeof dist), dfs(fx, fy);
                cout << max_dist << endl;
        }
        return 0;
}
