#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = tuple<double, int, int>;

class union_find {
private:
        vector<int> parents, rank;
        int size;

public:
        union_find(int n) : parents(n + 1), rank(n + 1, 0), size(n) {
                for(int u = 1; u <= n; ++u) {
                        parents[u] = u;
                }
        }

        int find_set(int u) {
                return u == parents[u] ? u : (parents[u] = find_set(parents[u]));
        }

        bool same_set(int u, int v) {
                return find_set(u) == find_set(v);
        }

        void union_set(int u, int v) {
                if(not same_set(u, v)) {
                        int x = find_set(u), y = find_set(v);
                        if(rank[x] >= rank[y]) {
                                parents[y] = parents[x];
                        } else {
                                parents[x] = parents[y];
                        }

                        if(rank[x] == rank[y]) ++rank[x];

                        --size;
                }
        }

        int count(void) {
                return size;
        }
};

int main(void) {
        int n, m;
        while(scanf("%d", &n) != EOF) {
                vector<ii> points(n + 1);
                for(int i = 1; i <= n; ++i) {
                        int x, y;
                        scanf("%d %d", &x, &y);
                        points[i] = ii(x, y);
                }

                priority_queue<edge, vector<edge>, greater<edge>> edges;
                for(int u = 1; u < n; ++u) {
                        for(int v = u + 1; v <= n; ++v) {
                                int x0, y0, xf, yf;
                                tie(x0, y0) = points[u];
                                tie(xf, yf) = points[v];
                                edges.push(edge(hypot(xf - x0, yf - y0), u, v));
                        }
                }

                union_find ufds(n);
                scanf("%d", &m);
                for(int i = 0; i < m; ++i) {
                        int u, v;
                        scanf("%d %d", &u, &v);
                        ufds.union_set(u, v);
                }

                double mst = 0.0;
                while(not edges.empty() && ufds.count() > 1) {
                        auto& current_edge = edges.top();
                        double w; int u, v;
                        tie(w, u, v) = current_edge;
                        if(not ufds.same_set(u, v)) {
                                ufds.union_set(u, v);
                                mst += w; 
                        }
                        edges.pop();
                }

                printf("%.2lf\n", mst);
        }

        return 0;
}
