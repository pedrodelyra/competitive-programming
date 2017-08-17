#include <bits/stdc++.h>

#define oo 0x3f3f3f3f

using namespace std;
using iii = tuple<int, int, int>;
using vii = vector<pair<int, int>>;

const int MAX = 128;

int  n, m, k, dist[MAX][MAX];
char grid[MAX][MAX];
vii  moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int dijkstra(int x0, int y0) {
        priority_queue<iii, vector<iii>, greater<iii>> pq;
        memset(dist, oo, sizeof dist);
        pq.push(iii(dist[x0][y0] = 0, x0, y0));
        while(not pq.empty()) {
                int curr_dist, x, y;
                tie(curr_dist, x, y) = pq.top(); pq.pop();

                if(curr_dist > dist[x][y]) continue;

                if(x == 1 || y == 1 || x == n || y == m) return curr_dist;

                for(auto& m : moves) {
                        int dx = m.first, dy = m.second,
                             w = (dx == 1 && grid[x + dx][y + dy] == 'v') || (dx == -1 && grid[x + dx][y + dy] == '^') ||
                                 (dy == 1 && grid[x + dx][y + dy] == '>') || (dy == -1 && grid[x + dx][y + dy] == '<');
                        bool valid_move = (dx && (grid[x + dx][y + dy] == 'v' || grid[x + dx][y + dy] == '^')) ||
                                          (dy && (grid[x + dx][y + dy] == '>' || grid[x + dx][y + dy] == '<'));
                        if(valid_move && dist[x + dx][y + dy] > curr_dist + w) {
                                pq.push(iii(dist[x + dx][y + dy] = curr_dist + w, x + dx, y + dy));
                        }
                }
        }
        return oo;
}

int main() {
        while(cin >> n >> m >> k, n | m | k) {
                memset(grid, 0, sizeof grid);
                for(int i = 1; i <= n; ++i) {
                        for(int j = 1; j <= m; ++j) {
                                cin >> grid[i][j];
                        }
                }
                cout << (dijkstra(n + 1 >> 1, m + 1 >> 1) <= k ? "Sim" : "Nao") << endl;
        }
        return 0;
}
