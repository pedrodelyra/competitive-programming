#include <bits/stdc++.h>

using namespace std;

bool lucky_number(int n) {
        string s = to_string(n);
        for(int i = 0; s[i]; ++i) {
                if(s[i] != '4' and s[i] != '7') {
                        return false;
                }
        }
        return true;
}

int main() {
        int n;
        cin >> n;
        bool ans = lucky_number(n);
        for(int i = 1; !ans and i <= n; ++i) {
                if(lucky_number(i) and n % i == 0) {
                        ans = true;
                }
        }
        cout << (ans ? "YES" : "NO") << endl;
        return 0;
}
