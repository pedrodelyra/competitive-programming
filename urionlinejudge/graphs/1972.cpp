#include <bits/stdc++.h>

using namespace std;
using ii  = pair<int, int>;
using iii = tuple<int, int, int>;

const int oo = 0x3f3f3f3f;

char grid[512][512];
int  dist[512][512];
vector<ii> movements = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int dijkstra(int x0, int y0, int xf, int yf) {
        priority_queue<iii, vector<iii>, greater<iii>> pq;
        memset(dist, oo, sizeof dist);
        pq.push(iii(dist[x0][y0] = 0, x0, y0));
        while(not pq.empty()) {
                iii curr_state = pq.top(); pq.pop();
                int curr_dist, x, y;
                tie(curr_dist, x, y) = curr_state;
                if(curr_dist == dist[x][y]) {
                        if(x == xf and y == yf) return curr_dist;
                        for(auto& move : movements) {
                                int dx = move.first, dy = move.second,
                                    w = isdigit(grid[x + dx][y + dy]) ? grid[x + dx][y + dy] - '0' : 0;
                                if(grid[x + dx][y + dy] != '#' and dist[x + dx][y + dy] > curr_dist + w) {
                                        pq.push(iii(dist[x + dx][y + dy] = curr_dist + w, x + dx, y + dy));
                                }
                        }
                }
        }
        return oo;
}

int main() {
        int m, n;
        cin >> n >> m;
        int x0, y0, xf, yf;
        memset(grid, '#', sizeof grid);
        for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) {
                        cin >> grid[i][j];
                        if(grid[i][j] == 'H') x0 = i, y0 = j;
                        if(grid[i][j] == 'E') xf = i, yf = j;
                }
        }
        int min_dist = dijkstra(x0, y0, xf, yf);
        if(min_dist < oo) {
                cout << min_dist << endl;
        } else {
                cout << "ARTSKJID" << endl;
        }
        return 0;
}
