#include <bits/stdc++.h>

using namespace std;
using lld = long long int;
using iii = tuple<int, int, int>;

class fenwick_tree {
private:
        vector<lld> fenwick;
        int n;

public:
        fenwick_tree(int sz) : n(sz), fenwick(sz + 5, 0) {}

        lld query(int idx) {
                lld sum = 0;
                while(idx) {
                        sum += fenwick[idx];
                        idx -= idx & -idx;
                }
                return sum;
        }

        void update(int idx, lld value) {
                while(idx <= n) {
                        fenwick[idx] += value;
                        idx += idx & -idx;
                }
        }

        void range_sum(int l, int r, lld x) {
                this->update(l, x);
                this->update(r + 1, -x);
        }

        vector<lld> tree() const {
                return fenwick;
        }
};

int main() {
        ios_base::sync_with_stdio(false);
        int n, m, k;
        cin >> n >> m >> k;
        vector<lld> a(n + 1);
        for(int i = 1; i <= n; ++i) {
                cin >> a[i];
        }
        vector<iii> queries(m + 1);
        for(int i = 1; i <= m; ++i) {
                int l, r, x;
                cin >> l >> r >> x;
                queries[i] = iii(l, r, x);
        }
        fenwick_tree f(m), add(n);
        for(int i = 0; i < k; ++i) {
                int l, r;
                cin >> l >> r;
                f.range_sum(l, r, 1);
        }
        for(int i = 1; i <= m; ++i) {
                int l, r, x;
                tie(l, r, x) = queries[i];
                add.range_sum(l, r, f.query(i) * x);
        }
        for(int i = 1; i <= n; ++i) {
                cout << a[i] + add.query(i) << " ";
        }
        cout << endl;
        return 0;
}
