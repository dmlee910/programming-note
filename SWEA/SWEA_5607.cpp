#include <iostream>
#include <memory.h>

using namespace std;

#define MOD 1234567891

int testCase, T;
int N, R;
int dp[1000000][1000000];

int combination(int a, int b)
{
    if (b == 0) {
        return 0;
    }
    else if (a == b) {
        return 1;
    }
    else if (b == 1) {
        return a;
    }

    int& ret = dp[a][b];

    if (ret != -1) return ret;

    ret = (combination(a - 1, b - 1) + combination(a - 1, b)) % MOD;

    return ret;
}

int main(void)
{
    memset(dp, -1, sizeof(dp));

    cin >> T;

    for (testCase = 1; testCase <= T; testCase++) {

        cin >> N >> R;

        int ans = combination(N, R);

        cout << "#" << testCase << ' ' << ans << endl;
    }

    return 0;
}