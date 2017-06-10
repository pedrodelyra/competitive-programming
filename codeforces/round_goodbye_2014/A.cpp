#include <bits/stdc++.h>

using namespace std;

const int MAX = 30005;

bool possible;
int n, t, a[MAX];

void dfs(int i) {
        if(i == t) {
                possible = true;
        } else if(i < n) {
                dfs(i + a[i]);
        }
}

int main() {
        cin >> n >> t;
        for(int i = 1; i < n; ++i) {
                cin >> a[i];
        }
        dfs(1);
        cout << (possible ? "YES" : "NO") << endl;
        return 0;
}
