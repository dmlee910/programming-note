#include <stdio.h>

using namespace std;

int main(void) {
    int N;
    int dp[1001];

    scanf("%d", &N);
    
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    //dp[3] = 3;

    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
    }

    printf("%d", dp[N]);
    
    return 0;
}