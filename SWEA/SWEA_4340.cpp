#include <iostream>
// #include <string.h>

using namespace std;

#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3

int testCase, T, N;
int map[50][50];
int dx[] = { 0, -1, 0, 1 }; // 좌, 상, 우, 하
int dy[] = { -1, 0, 1, 0 };
//int dp[50][50][7];
bool visited[50][50];
int final_min;

void dfs(int x, int y, int cur, int dir, int cnt)
{
    if (x < 0 || y < 0 || x >= N || y >= N || map[x][y] == 0 || visited[x][y] == true) {
        return;
    }
    if (cnt > final_min) {
        return;
    }
    if (N - 1 - x + N - 1 - y + cnt > final_min) return;
    if (x == N - 1 && y == N - 1 && final_min > cnt && (cur == 1 || cur == 6)) {
        final_min = cnt;
        return;
    }
    
    //if (dp[x][y][cur] != 0 && dp[x][y][cur] < cnt) return;

    //dp[x][y][cur] = cnt;
    visited[x][y] = true;

    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (dir == LEFT) {
        if (map[nx][ny] <= 2) {
            dfs(nx, ny, 1, LEFT, cnt + 1);
        }
        else {
            dfs(nx, ny, 3, DOWN, cnt + 1);
            dfs(nx, ny, 6, UP, cnt + 1);
        }
    }
    else if (dir == UP) {
        if (map[nx][ny] <= 2) {
            dfs(nx, ny, 2, UP, cnt + 1);
        }
        else {
            dfs(nx, ny, 3, RIGHT, cnt + 1);
            dfs(nx, ny, 4, LEFT, cnt + 1);
        }
    }
    else if (dir == RIGHT) {
        if (map[nx][ny] <= 2) {
            dfs(nx, ny, 1, RIGHT, cnt + 1);
        }
        else {
            dfs(nx, ny, 4, DOWN, cnt + 1);
            dfs(nx, ny, 5, UP, cnt + 1);
        }
    }
    else if (dir == DOWN) {
        if (map[nx][ny] <= 2) {
            dfs(nx, ny, 2, DOWN, cnt + 1);
        }
        else {
            dfs(nx, ny, 5, LEFT, cnt + 1);
            dfs(nx, ny, 6, RIGHT, cnt + 1);
        }
    }
    visited[x][y] = false;
    return;
}

int main(void)
{
    scanf("%d", &T);
   
    for (testCase = 0; testCase < T; testCase++) {
        scanf("%d", &N);
        // memset(dp, 0, sizeof(dp));
        // memset(map, 0, sizeof(map));
        final_min = 3000;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &map[i][j]);
                visited[i][j] = false;
            }
        }

        dfs(0, 0, map[0][0], RIGHT, 1);

        // int ans = map[N - 1][N - 1] <= 2 ? dp[N - 1][N - 1][1] : dp[N - 1][N - 1][6];

        //printf("#%d %d\n", testCase + 1, ans);
        printf("#%d %d\n", testCase + 1, final_min);
    }

#if 0
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 1; k <= 6; k++) {
                printf("dp[%d][%d][%d] : %d\n", i, j, k, dp[i][j][k]);
            }
        }
    }
#endif

    return 0;
}