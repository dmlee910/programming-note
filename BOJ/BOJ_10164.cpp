#include <stdio.h>

using namespace std;

int main(void) {
    int N, M, K;
    int dp[16][16];
    int result = 0;

    scanf("%d %d %d", &N, &M, &K);

    if (K != 0) {
        int row = K % M == 0 ? K / M : K / M + 1;
        int col = K % M == 0 ? M : K % M;

        for (int x = 1; x <= row; x++) {
            for (int y = 1; y <= col; y++) {
                if (x == 1 || y == 1) {
                    dp[x][y] = 1;
                }
                else {
                    dp[x][y] = dp[x - 1][y] + dp[x][y - 1];
                }
            }
        }

        for (int x = row; x <= N; x++) {
            for (int y = col; y <= M; y++) {
                if (x == row && y == col) continue;
                else if (x == row || y == col) {
                    dp[x][y] = 1;
                }
                else {
                    dp[x][y] = dp[x - 1][y] + dp[x][y - 1];
                }
            }
        }

        result = dp[row][col] * dp[N][M];
    }
    else {
        for (int x = 1; x <= N; x++) {
            for (int y = 1; y <= M; y++) {
                if (x == 1 || y == 1) {
                    dp[x][y] = 1;
                }
                else {
                    dp[x][y] = dp[x - 1][y] + dp[x][y - 1];
                }
            }
        }

        result = dp[N][M];
    }

    printf("%d\n", result);

    return 0;
}