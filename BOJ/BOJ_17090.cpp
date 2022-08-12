#include <iostream>
#include <memory.h>

using namespace std;

int row, col;
char map[500][500];
int visited[500][500];

int dfs(int x, int y) {
    if (x < 0 || x >= row || y < 0 || y >= col) {
        return 1;
    }
    if (visited[x][y] != -1) {
        return visited[x][y];
    }
    visited[x][y]++;

    int nx, ny;
    if (map[x][y] == 'U') {
        nx = x-1;
        ny = y;
    }
    else if (map[x][y] == 'R') {
        nx = x;
        ny = y+1;
    }
    else if (map[x][y] == 'D') {
        nx = x+1;
        ny = y;
    }
    else if (map[x][y] == 'L') {
        nx = x;
        ny = y-1;
    }
    
    visited[x][y] = dfs(nx, ny);
    return visited[x][y];
}

int main(void) {
    memset(visited, -1, sizeof(visited));

    scanf("%d %d", &row, &col);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf(" %c", &map[i][j]);
        }
    }

    int result = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result += dfs(i, j);
        }
    }

    printf("%d\n", result);

    return 0;
}