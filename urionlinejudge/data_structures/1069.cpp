#include <bits/stdc++.h>

using namespace std;

int main() {
        int tc;
        cin >> tc;
        while(tc--) {
                string s;
                cin >> s;
                int count = 0, diamonds = 0;
                for(char c : s) {
                        if(c == '<') {
                                ++count;
                        } else if(c == '>' and count) {
                                --count;
                                ++diamonds;
                        }
                }
                cout << diamonds << endl;
        }
        return 0;
}
