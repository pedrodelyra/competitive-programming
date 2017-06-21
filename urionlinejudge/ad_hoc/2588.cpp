#include <bits/stdc++.h>

using namespace std;

int main() {
        string s;
        while(cin >> s) {
                vector<int> f(256, 0);
                for(int i = 0; s[i]; ++i)
                        f[s[i]]++;
                int odds = 0;
                for(char c = 'a'; c <= 'z'; ++c)
                        if(f[c] & 1) ++odds;
                cout << max(odds - 1, 0) << endl;
        }
        return 0;
}
