#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int oo = 0x3f3f3f3f, MAX = 1 << 8;

vector<ii>  graph[2][MAX];
int dist[2][MAX];

int dijkstra(int source, int destination, int t) {
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        memset(dist[t], oo, sizeof dist[t]);
        pq.push(ii(dist[t][source] = 0, source));
        while(not pq.empty()) {
                auto curr_state = pq.top(); pq.pop();
                int curr_dist = curr_state.first, u = curr_state.second;

                if(curr_dist > dist[t][u]) continue;

                if(u == destination) break;

                for(auto& curr_edge : graph[t][u]) {
                        int w = curr_edge.first, v = curr_edge.second;
                        if(dist[t][v] > curr_dist + w) {
                                pq.push(ii(dist[t][v] = curr_dist + w, v));
                        }
                }
        }
        return dist[t][destination];
}

int main() {
        int n, m;
        while(~scanf("%d %d", &n, &m)) {
                for(int i = 1; i <= m; ++i) {
                        int u, v, t, w;
                        scanf("%d %d %d %d", &u, &v, &t, &w);
                        graph[t][u].push_back(ii(w, v));
                }
                printf("%d\n", min(dijkstra(1, n, 0), dijkstra(1, n, 1)));
                for(int t = 0; t < 2; ++t) {
                        for(int u = 1; u <= n; ++u) graph[t][u].clear();
                }
        }
        return 0;
}
