#include <bits/stdc++.h>

using namespace std;
using ii  = pair<int, int>;
using iii = tuple<int, int, bool>;

const int MAX_N = 1e4 + 5, oo = 1e9;

vector<iii> graph[MAX_N];
vector<int> dist(MAX_N);

void dijkstra(int source, bool enable_secret_routes) {
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        fill(begin(dist), end(dist), oo);
        pq.push(ii(dist[source] = 0, source));
        while(not pq.empty()) {
                auto curr_state = pq.top(); pq.pop();
                int curr_dist, u;
                tie(curr_dist, u) = curr_state;
                if(curr_dist == dist[u]) {
                        for(auto& curr_edge : graph[u]) {
                                int v, w, is_secret_route;
                                tie(v, w, is_secret_route) = curr_edge;
                                if(not enable_secret_routes and is_secret_route) continue;
                                if(dist[v] > curr_dist + w) {
                                        pq.push(ii(dist[v] = curr_dist + w, v));
                                }
                        }
                }
        }
}

int main() {
        int n, m, k, p;
        cin >> n >> m >> k >> p;
        for(int i = 0; i < m + k; ++i) {
                int u, v, w;
                cin >> u >> v >> w;
                graph[u].push_back(iii(v, w, i >= m));
                graph[v].push_back(iii(u, w, i >= m));
        }
        vector<int> criminals(p + 1);
        for(int i = 1; i <= p; ++i) {
                cin >> criminals[i];
        }
        int s, t, agents_dist;
        cin >> s >> t;
        dijkstra(s, false);
        agents_dist = dist[t];
        dijkstra(t, true);
        int count = 0;
        for(int i = 1; i <= p; ++i) {
                if(dist[criminals[i]] <= agents_dist)
                        ++count;
        }
        cout << count << endl;
        return 0;
}
