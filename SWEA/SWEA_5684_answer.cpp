#include <iostream>
#include <vector>
#include <cstring>

#define endl "\n"
#define MAX 410

using namespace std;

int N, M, Answer;
int Entry[MAX];
bool Visit[MAX];
vector<pair<int, int>> V[MAX];

int Min(int A, int B) { if (A < B) return A; return B; }

void Initialize()
{
    for (int i = 0; i < MAX; i++) {
        Entry[i] = 0;
        V[i].clear();
        Visit[i] = false;
    }
    Answer = 2e9;
}

void Input()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        V[a].push_back(make_pair(b, c));
        Entry[b]++;
    }
}

void DFS(int Cur, int Sum, int Start)
{
    Visit[Cur] = true;
    for (int i = 0; i < V[Cur].size(); i++) {
        int Next = V[Cur][i].first;
        int Cost = V[Cur][i].second;

        if (Visit[Next] == false) {
            if (Sum + Cost < Answer) DFS(Next, Sum + Cost, Start);
        }
        else {
            if (Next == Start) Answer = Min(Answer, Sum + Cost);
        }
    }
}

void Solution()
{
    for (int i = 1; i <= N; i++) {
        if (Entry[i] == 0) continue;

        memset(Visit, false, sizeof(Visit));
        DFS(i, 0, i);
    }
}

void Solve()
{
    int Tc; cin >> Tc;
    for (int T = 1; T <= Tc; T++) {
        Initialize();
        Input();
        Solution();

        cout << "#" << T << " " << Answer << endl;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();

    return 0;
}