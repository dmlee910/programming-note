// 외판원 문제
// 대표적인 문제이므로 다시 풀어보기

#include <iostream>
#include <memory.h>

using namespace std;

#define INF 987654321

int N;
int W[16][16];
int cost[16][1 << 16];
int answer_bit;

int dfs(int cur, int visited)
{
    if (visited == answer_bit) {
        if (W[cur][0] == 0) return INF;
        else return W[cur][0];
    }

    if (cost[cur][visited] != -1) cost[cur][visited];
    cost[cur][visited] = INF;

    for (int i = 0; i < N; i++) {
        if (W[cur][i] == 0) continue;
        if (visited & (1 << i)) continue;
        int nv = visited | 1 << i;

        cost[cur][visited] = min(cost[cur][visited], W[cur][i] + dfs(i, nv));
    }

    return cost[cur][visited];
}

int main(void)
{
    memset(W, -1, sizeof(W));
    memset(cost, -1, sizeof(cost));

    cin >> N;

    answer_bit = (1 << N) - 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> W[i][j];
        }
    }

    int answer = dfs(0, 1);

    cout << answer << endl;

    return 0;
}