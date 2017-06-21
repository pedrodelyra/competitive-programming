#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

int main() {
        int n, m;
        cin >> n >> m;
        vector<int> v(n + 1);
        for(int i = 1; i <= n; ++i)
                cin >> v[i];

        vector<int> c(m + 1);
        for(int i = 1; i <= m; ++i)
                cin >> c[i];

        priority_queue<ii, vector<ii>, greater<ii>> pq;
        for(int i = 1; i <= n; ++i)
                pq.push(ii(0, i));

        for(int i = 1; i <= m; ++i) {
                ii curr = pq.top(); pq.pop();
                int t = curr.first, idx = curr.second;
                pq.push(ii(t + v[idx] * c[i], idx));
        }
        int finish;
        while(not pq.empty())
                finish = pq.top().first, pq.pop();

        cout << finish << endl;
        return 0;
}
