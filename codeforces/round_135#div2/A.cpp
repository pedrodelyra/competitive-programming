#include <bits/stdc++.h>

using namespace std;

int main() {
        int k; string s, k_str = "";
        cin >> k; cin >> s;
        map<char, int> f;
        for(int i = 0; s[i]; ++i) {
                f[s[i]]++;
        }
        bool possible = true;
        for(auto& p : f) {
                if(p.second % k == 0) {
                        k_str += string(p.second / k, p.first);
                } else {
                        possible = false;
                }
        }
        if(possible) {
                while(k--) {
                        cout << k_str;
                }
                cout << endl;
        } else {
                cout << -1 << endl;
        }
        return 0;
}
