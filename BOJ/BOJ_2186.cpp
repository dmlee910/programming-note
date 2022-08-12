#include <iostream>
#include <cstring>

using namespace std;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

int N, M, K;
char map[100][100];
int dp[100][100][80];
string input;

int dfs(int x, int y, int count)
{
    if (dp[x][y][count] != -1) { return dp[x][y][count]; }
    if (count == input.size() - 1) {
        return 1;
    }

    dp[x][y][count] = 0;
    for (int l = 1; l <= K; l++) {
        for (int i = 0; i < 4; i ++) { // 동서남북 네 방향
            int nx = x + (dx[i] * l);
            int ny = y + (dy[i] * l);

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }

            if (map[nx][ny] == input[count + 1]) {
                dp[x][y][count] += dfs(nx, ny, count + 1);
            }
            else {
                continue;
            }
        }
    } 

    return dp[x][y][count];
}

int main(void)
{
    scanf("%d %d %d", &N, &M, &K);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    cin >> input;

    memset(dp, -1, sizeof(dp));

#if 0
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << map[i][j];
        }
        printf("\n");
    }
    cout << input;
#endif

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == input[0]) {
                ans += dfs(i, j, 0);
            }
        }
    }

    printf("%d\n", ans);

    return 0;
    }