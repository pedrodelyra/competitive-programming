#include <bits/stdc++.h>

using namespace std;

int main() {
        string s;
        while(cin >> s) {
                int  count = 0;
                bool correct = true;
                for(char c : s) {
                        if(c == '(') {
                                ++count;
                        } else if(c == ')') {
                                if(count) {
                                        --count;
                                } else {
                                        correct = false;
                                }
                        }
                }
                if(count) correct = false;
                cout << (correct ? "correct" : "incorrect") << endl;
        }
        return 0;
}
