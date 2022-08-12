#include <iostream>

using namespace std;

int testCase, T;
int W, H;
int map[10][25];
int dp[1 << 10][24];
int ans = 0;

bool check(int x, int y)
{
    bool retVal = false;

    if (x >= H || y >= W) {
        // nothing;
    }
    else if (map[x][y] == 0 && map[x + 1][y] == 0 && map[x][y + 1] == 0 && map[x + 1][y + 1] == 0) {
        retVal = true;
    }

    return retVal;
}

void dfs(int x, int y, int cnt)
{
    if (x >= H - 1) {
        x = 0;
        y++;
    }

    if (y == W - 1) {
        ans = ans < cnt ? cnt : ans;
        return;
    }

    if (check(x, y)) {
        map[x][y] = map[x + 1][y] = map[x][y + 1] = map[x + 1][y + 1] = 1;
        dfs(x + 2, y, cnt + 1);
        map[x][y] = map[x + 1][y] = map[x][y + 1] = map[x + 1][y + 1] = 0;
    }
    dfs(x + 1, y, cnt + 1);
}

int main(void)
{
    scanf("%d", &T);
    scanf("%d %d", &W, &H);

    for (testCase = 0; testCase < T; testCase++) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        dfs(0, 0, 0);
    }

    return 0;
}