#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int testCase, T;
int N, M;
vector<pair<int, int>> V[401];
bool visited[401];
int answer;

void input()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;

        V[s].push_back(make_pair(e, c));
    }
}

void initialize()
{
    for (int i = 0; i < 401; i++)
    {
        V[i].clear();
        visited[i] = false;
    }
    answer = 2e9;
}

void solution(int cur, int sum, int start)
{
    visited[cur] = true;

    for (int i = 0; i < V[cur].size(); i++)
    {
        int next = V[cur][i].first;
        int cost = V[cur][i].second;

        if (visited[next] == false)
        {
            if (sum + cost < answer)
            {
                solution(next, sum + cost, start);
            }
        }
        else {
            if (next == start)
            {
                answer = sum + cost < answer ? sum + cost : answer;
            }
        }
    }
}

void solve()
{
    cin >> T;
    
    for (testCase = 1; testCase <= T; testCase++)
    {
        initialize();
        input();

        for (int i = 1; i <= N; i++)
        {
            memset(visited, false, sizeof(visited));
            solution(i, 0, i);
        }

        answer = answer == 2e9 ? -1 : answer;
        cout << "#" << testCase << " " << answer << endl;
    }
}

int main(void)
{
    solve();

    return 0;
}