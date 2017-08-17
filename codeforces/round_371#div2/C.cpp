#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

lld pattern(lld x) {
        lld bitmask = 0, pwrten = 1;
        for(int i = 0; x; ++i, x /= 10, pwrten *= 10) {
                if(x % 10 & 1) bitmask += pwrten;
        }
        return bitmask;
}

int main() {
        int queries;
        scanf("%d", &queries);
        map<lld, int> s;
        while(queries--) {
                char op; lld x;
                scanf(" %c %lld", &op, &x);
                switch(op) {
                        case '+':
                                s[pattern(x)]++;
                                break;
                        case '-':
                                s[pattern(x)]--;
                                break;
                        case '?':
                                printf("%d\n", s[x]);
                                break;
                }
        }
        return 0;
}
