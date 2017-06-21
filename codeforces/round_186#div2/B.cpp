#include <bits/stdc++.h>

using namespace std;

int main() {
        string s;
        cin >> s;
        vector<int> f(s.size() + 1, 0);
        for(int i = 0; s[i]; ++i)
                f[i + 1] = f[i] + (s[i] == s[i + 1]);
        int q;
        cin >> q;
        while(q--) {
                int l, r;
                cin >> l >> r;
                cout << f[r - 1] - f[l - 1] << endl;
        }
        return 0;
}
