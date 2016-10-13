#include <bits/stdc++.h>

#define MAX 10005

using namespace std;
using ii = pair<int, int>;

vector<ii> graph[MAX];
int max_node, paths, total_cost, visited[MAX];

void dfs(int u) {
        visited[u] = true;
        max_node = max(max_node, u);
        for(auto& current_edge : graph[u]) {
                int w = current_edge.first, v = current_edge.second;
                if(not visited[v]) {
                        dfs(v);
                }

                total_cost += w;
                ++paths;
        }

}

double avrg_holes(int total_holes, int num_paths) {
        if(total_holes == 0 || num_paths == 0)
                return 0;
        else
                return total_holes / (double) num_paths;
}

int main(void) {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; ++i) {
                int u, v, w;
                scanf("%d %d %d", &u, &v, &w);
                graph[u].push_back(ii(w, v));
                graph[v].push_back(ii(w, u));
        }

        int ans = 0; double min_cost = DBL_MAX;
        for(int u = 1; u <= n; ++u) {
                if(not visited[u]) {
                        paths = total_cost = max_node = 0;
                        dfs(u);
                        double current_cost = avrg_holes(total_cost, paths);
                        if(current_cost < min_cost) {
                                min_cost = current_cost;
                                ans = max_node;
                        } else if(current_cost == min_cost) {
                                ans = max(ans, max_node);
                        }
                }
        }

        printf("%d\n", ans);

        return 0;
}
