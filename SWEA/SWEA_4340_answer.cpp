#include<iostream>

using namespace std;
int input_map[50][50];
bool visit[50][50];
int final_min;
int N;

void bt(int prev_x, int prev_y, int idx_x, int idx_y, int cnt)
{
    int next_x, next_y;
    if (cnt > final_min)
    {
        return;
    }
    else if (idx_x == 0 && idx_y == -1)
    {
        if (cnt < final_min)
            final_min = cnt;
        return;
    }
    else if (idx_x < 0 || N <= idx_x || idx_y < 0 || N <= idx_y)
    {
        return;
    }
    else if (visit[idx_x][idx_y])
    {
        return;
    }
    else if (input_map[idx_x][idx_y] == 0)
    {
        return;
    }
    else if (idx_x + idx_y + cnt > final_min)
    {
        return;
    }

    // cout << "idx_x : " << idx_x << " idx_y : " << idx_y<< endl;
    visit[idx_x][idx_y] = true;
    if (input_map[idx_x][idx_y] < 3)
    {
        //막대일 경우
        if (prev_x == idx_x)
        {
            // case 1
            next_x = idx_x;
            next_y = idx_y + idx_y - prev_y;
        }
        else
        {
            // case 2
            next_x = idx_x + idx_x - prev_x;
            next_y = idx_y;
        }
        bt(idx_x, idx_y, next_x, next_y, cnt + 1);
    }
    else
    {
        //꺾은 파이프
        if (prev_x == idx_x)
        {
            // up or down
            bt(idx_x, idx_y, idx_x - 1, idx_y, cnt + 1);
            bt(idx_x, idx_y, idx_x + 1, idx_y, cnt + 1);
        }
        else
        {
            // left or right
            bt(idx_x, idx_y, idx_x, idx_y - 1, cnt + 1);
            bt(idx_x, idx_y, idx_x, idx_y + 1, cnt + 1);
        }
    }
    visit[idx_x][idx_y] = false;
    return;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        final_min = 3000;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                cin >> input_map[i][j];
                visit[i][j] = false;
            }
        }
        bt(N - 1, N, N - 1, N - 1, 0);
        cout << "#" << test_case << " " << final_min << endl;
    }

    return 0;
}