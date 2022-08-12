#include <iostream>
#include <memory.h>

using namespace std;

int N;
int map[500][500];
int dp[500][500];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

int max(int a, int b)
{
    if (a > b) return a;
    return b;
}

int dfs(int x, int y)
{
    if (dp[x][y]) return dp[x][y];
    dp[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
            continue;
        }

        if (map[x][y] < map[nx][ny]) {
            dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
        }
    }

    return dp[x][y];
}

int main(void)
{
    memset(dp, 0, sizeof(dp));
    
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans = max(ans, dfs(i, j));
        }
    }

    printf("%d\n", ans);

    return 0;
}