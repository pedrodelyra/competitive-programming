#include <cstdio>

using namespace std;

int main(void) {
        int n, tc = 0;
        while(scanf("%d", &n), n) {
                int count[4] = {0, 0, 0, 0}, coins[4] = {50, 10, 5, 1};
                for(int i = 0; i < 4 && n; ++i) {
                        while(n >= coins[i]) {
                                n -= coins[i];
                                ++count[i];
                        }
                }

                printf("Teste %d\n", ++tc);
                for(int i = 0; i < 4; ++i) {
                        if(i) printf(" ");
                        printf("%d", count[i]);
                }
                printf("\n\n");
        }

        return 0;
}

