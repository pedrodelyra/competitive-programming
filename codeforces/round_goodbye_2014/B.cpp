#include <bits/stdc++.h>

using namespace std;

const int MAX = 512;

vector<int> graph[MAX], c(MAX);
bool visited[MAX];

void dfs(int u, int k) {
        visited[u] = true;
        for(auto& v : graph[u]) {
                if(not visited[v]) {
                        dfs(v, k);
                }
        }
        c[u] = k;
}

int main() {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; ++i) {
                cin >> a[i];
        }
        for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                        char x;
                        cin >> x;
                        if(x - '0') graph[i].push_back(j);
                }
        }
        int k = 0;
        for(int u = 1; u <= n; ++u) {
                if(not visited[u]) {
                        dfs(u, ++k);
                }
        }
        for(int cc = 1; cc <= k; ++cc) {
                for(int i = 1; i < n; ++i) {
                        if(c[i] != cc) continue;
                        for(int j = i + 1; j <= n; ++j) {
                                if(c[j] == cc and a[j] < a[i]) {
                                        swap(a[i], a[j]);
                                }
                        }
                }
        }
        for(int i = 1; i <= n; ++i) {
                cout << a[i] << " ";
        }
        cout << endl;
        return 0;
}
