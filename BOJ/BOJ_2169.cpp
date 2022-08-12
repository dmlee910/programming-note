#include <iostream>
#include <memory.h>

using namespace std;

int N, M;
int map[1000][1000];
int dx[] = { 0, 1, 0 };
int dy[] = {-1, 0, 1 }; // 좌, 하, 우
int visited[1000][1000];
int final_sum = 0;

void dfs(int x, int y, int sum)
{
    if (visited[x][y] == 1) return;

    sum += map[x][y];

    if (x == N - 1 && y == M - 1) {
        final_sum = final_sum < sum ? sum : final_sum;
        return;
    }

    visited[x][y] = 1;
    for (int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

        dfs(nx, ny, sum);
    }
    visited[x][y] = -1;

    return;
}

int main(void)
{
    memset(map, -1, sizeof(map));
    memset(visited, -1, sizeof(visited));

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    dfs(0, 0, 0);

    cout << final_sum << endl;

    return 0;
}