#include <iostream>

using namespace std;

#define MOD 100000

int dp[15][15][2][2];

int main(void) {
    int w, h;

    scanf("%d %d", &w, &h);

    for (int i = 0; i < w; i++) {
        dp[i][0][1][1] = 1;
    }
    for (int j = 0; j < h; j++) {
        dp[0][j][0][1] = 1;
    }

    for (int i = 1; i < w; i++) {
        for (int j = 1; j < h; j++) {
            dp[i][j][0][0] = dp[i][j-1][1][1] % MOD;
            dp[i][j][0][1] = (dp[i][j-1][0][0] + dp[i][j-1][0][1]) % MOD;
            dp[i][j][1][0] = dp[i-1][j][0][1] % MOD;
            dp[i][j][1][1] = (dp[i-1][j][1][0] + dp[i-1][j][1][1]) % MOD;
        }
    }

    printf("%d\n", (dp[w-1][h-1][0][0] + dp[w-1][h-1][0][1] + dp[w-1][h-1][1][0] + dp[w-1][h-1][1][1]) % MOD);

    return 0;
}