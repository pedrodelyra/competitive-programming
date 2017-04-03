#include <bits/stdc++.h>

using namespace std;

int main() {
        string a, b;
        cin >> a >> b;
        int n;
        cin >> n;
        while(n--) {
                string x, y;
                cin >> x >> y;
                cout << a << " " << b << endl;
                (a == x ? a : b) = y;
        }
        cout << a << " " << b << endl;
        return 0;
}
