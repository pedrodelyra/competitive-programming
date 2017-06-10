#include <bits/stdc++.h>

using namespace std;

int main() {
        string s;
        cin >> s;
        int n = s.length() - 1, p = 0;
        for(int i = n; i >= 0; --i) {
                if(s[i] == '0') {
                        p = i;
                }
        }
        s.erase(s.begin() + p);
        cout << s << endl;
        return 0;
}
