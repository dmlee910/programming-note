#include <iostream>
#include <memory.h>

using namespace std;

int map[17][17];
int dp[17][17][3]; // 가로:0 세로:1 대각선:2

int main(void) {
    memset(map, 0, sizeof(map));
    memset(dp, 0, sizeof(dp));

    int N;

    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    
    dp[1][2][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 3; j <= N; j++) {
            if (map[i][j] == 1)
                continue;
            
            dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
            dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];

            if (map[i - 1][j] != 1 && map[i][j - 1] != 1)
                dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
        }
    }

#if 0
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k < 3; k++) {
                printf("[%d][%d][%d] %d\n", i, j, k, dp[i][j][k]);
            }
        }
        printf("\n");
    }
#endif
    
    printf("%d\n", dp[N][N][0] + dp[N][N][1] + dp[N][N][2]);

    return 0;
}