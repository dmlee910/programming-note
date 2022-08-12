#include <stdio.h>

using namespace std;

#define FULL_BIT 1023
#define MOD 1000000000

int dp[101][10][1<<10];

int main(void) {
    int N;

    scanf("%d", &N);

    dp[1][0][1] = 0;
    dp[1][1][2] = 1;
    dp[1][2][4] = 1;
    dp[1][3][8] = 1;
    dp[1][4][16] = 1;
    dp[1][5][32] = 1;
    dp[1][6][64] = 1;
    dp[1][7][128] = 1;
    dp[1][8][256] = 1;
    dp[1][9][512] = 1;

    for (int i = 2; i <= N; i++) {
        for (int m = 0; m <= 9; m++) {
            for (int k = 1; k < 1<<10; k++) {
                if (m == 0) {
                    dp[i][m][k | 1<<m] += dp[i-1][m+1][k];
                    dp[i][m][k | 1<<m] %= MOD;
                }
                else if (m == 9) {
                    dp[i][m][k | 1<<m] += dp[i-1][m-1][k];
                    dp[i][m][k | 1<<m] %= MOD;
                }
                else {
                    dp[i][m][k | 1<<m] += dp[i-1][m-1][k] + dp[i-1][m+1][k];
                    dp[i][m][k | 1<<m] %= MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans = (ans + dp[N][i][FULL_BIT]) % MOD;
    }

    printf("%d\n", ans);

    return 0;
}