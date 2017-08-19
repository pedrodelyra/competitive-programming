#include <bits/stdc++.h>

using namespace std;
using edge = pair<int, string>;

int main() {
        int n, tc = 0;
        while(cin >> n) {
                vector<string> beverages(n);
                for(int i = 0; i < n; ++i) {
                        cin >> beverages[i];
                }
                int m; cin >> m;
                map<string, vector<edge>> graph;
                map<string, int> in_degree;
                for(int i = 0; i < m; ++i) {
                        string u, v;
                        cin >> u >> v;
                        graph[u].push_back(edge(distance(begin(beverages), find(begin(beverages), end(beverages), v)), v));
                        in_degree[v]++;
                }
                priority_queue<edge, vector<edge>, greater<edge>> pq;
                for(int i = 0; i < beverages.size(); ++i) {
                        string u = beverages[i];
                        if(in_degree[u] == 0) {
                                pq.push(edge(i, u));
                        }
                }
		cout << "Case #" << ++tc << ": Dilbert should drink beverages in this order:";
                while(not pq.empty()) {
                        auto u = pq.top().second; pq.pop();
                        cout << " " << u;
                        for(auto& curr_edge : graph[u]) {
                                string v = curr_edge.second; int idx = curr_edge.first;
                                if(--in_degree[v] == 0) {
                                        pq.push(edge(idx, v));
                                }
                        }
                }
                cout << "." << endl << endl;
        }
        return 0;
}
