#include <iostream>
#include <memory.h>

using namespace std;

#define H 99

int N, M;
int map[50][50];
int dp[50][50];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
bool visited[50][50];

int dfs(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M || map[x][y] == H) return 0;
    if (visited[x][y] == true) {
        printf("-1\n");
        exit(0);
    }
    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y]++;

    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i] * map[x][y];
        int ny = y + dy[i] * map[x][y];

        dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
    }
    visited[x][y] = false;

    return dp[x][y];
}

int main(void) {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            scanf(" %1c", &c);
            map[i][j] = c == 'H' ? H : c - '0';
        }
    }

    memset(dp, -1, sizeof(dp));

#if 0
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
#endif

    printf("%d\n", dfs(0, 0));

    return 0;
}