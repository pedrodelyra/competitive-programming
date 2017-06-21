#include <bits/stdc++.h>

using namespace std;

int main() {
        int n;
        while(cin >> n) {
                vector<string> s(n);
                for(int i = 0; i < n; ++i) {
                        cin >> s[i];
                }
                sort(s.begin(), s.end());
                int count = 0;
                for(int i = 0; i < n - 1; ++i) {
                        int j = 0;
                        while(s[i][j] == s[i + 1][j]) ++j;
                        count += j;
                }
                cout << count << endl;
        }
        return 0;
}
