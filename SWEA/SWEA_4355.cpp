#include <iostream>

using namespace std;

int testCase, T;
int N;
int dp[20][1 << 20][3]; // 가로(0) 세로(1) 높이(2)
int box[20][3]; // 가로 세로 높이

int getLength(int cur, int visited, int mode)
{
    for (int i = 0; i < N; i++) {
    }
}

int main(void)
{
    scanf("%d", &T);
    
    for (testCase = 1; testCase <= T; testCase++) {
        scanf("%d", &N);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 1 << N; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = 0;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &box[i][0], &box[i][1], &box[i][2]);
        }
    }

    int visited = 0x0000;

    return 0;
}