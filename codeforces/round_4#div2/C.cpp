#include <bits/stdc++.h>

using namespace std;

map<string, int> f;

int main() {
        int n;
        cin >> n;
        while(n--) {
                string s;
                cin >> s;
                cout << (f[s]++ ? s + to_string(f[s] - 1) : "OK") << endl;
        }
        return 0;
}
