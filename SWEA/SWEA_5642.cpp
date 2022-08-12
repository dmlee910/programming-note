#include <iostream>
#include <memory.h>

using namespace std;

int testCase, T;
int N;
int num[100000];
int final_max = -987654321;
int dp[100000];

void input(int n)
{
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
}

void solution(int n)
{
    for (int i = 0; i < n; i++) {
        dp[i] = num[i];

        if (i == 0) continue;
        
        if (dp[i] < dp[i - 1] +)
    }

    cout << "#" << testCase << ' ' << final_max << endl;
}

int main(void)
{
    cin >> T;

    for (testCase = 1; testCase <= T; testCase++) {
        memset(num, 0, sizeof(num));
        memset(dp, 0, sizeof(dp));

        cin >> N;

        input(N);
        solution(N);
    }

    return 0;
}