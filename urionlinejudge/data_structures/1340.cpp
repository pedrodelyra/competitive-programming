#include <bits/stdc++.h>

using namespace std;

int main() {
        int n;
        while(cin >> n) {
                stack<int> s;
                queue<int> q;
                priority_queue<int> p;
                bool is_s = true, is_q = true, is_p = true;
                for(int i = 1; i <= n; ++i) {
                        int command, x;
                        cin >> command >> x;
                        switch(command) {
                                case 1:
                                        s.push(x);
                                        q.push(x);
                                        p.push(x);
                                        break;
                                case 2:
                                        is_s &= s.top()   == x; s.pop();
                                        is_q &= q.front() == x; q.pop();
                                        is_p &= p.top()   == x; p.pop();
                                        break;
                        }
                }
                if(is_s and not is_q and not is_p) {
                        cout << "stack" << endl;
                } else if(is_q and not is_s and not is_p) {
                        cout << "queue" << endl;
                } else if(is_p and not is_s and not is_q) {
                        cout << "priority queue" << endl;
                } else if(not is_s and not is_q and not is_p) {
                        cout << "impossible" << endl;
                } else {
                        cout << "not sure" << endl;
                }
        }
        return 0;
}
