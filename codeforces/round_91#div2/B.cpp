#include <bits/stdc++.h>

using namespace std;

int main() {
        string s;
        cin >> s;
        int x = 0, y = 0, z = 0;
        for(int i = 0; s[i]; ++i) {
                if(s[i] == '4') {
                        ++x;
                } else if(s[i] == '7') {
                        ++y;
                } else {
                        ++z;
                }
        }
        cout << (z == s.length() ? -1 : (x >= y ? 4 : 7)) << endl;
        return 0;
}
