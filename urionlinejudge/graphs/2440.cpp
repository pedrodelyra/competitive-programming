#include <bits/stdc++.h>

#define MAX 100005

using namespace std;

vector<int> graph[MAX];
bitset<MAX> visited;

void dfs(int u) {
        visited[u] = true;
        for(auto& v : graph[u]) {
                if(not visited[v])
                        dfs(v);
        }
}

int main() {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= m; ++i) {
                int u, v;
                cin >> u >> v;
                graph[u].push_back(v);
                graph[v].push_back(u);
        }
        int count = 0;
        for(int u = 1; u <= n; ++u) {
                if(not visited[u]) {
                        dfs(u);
                        count++;
                }
        }
        cout << count << endl;
        return 0;
}
