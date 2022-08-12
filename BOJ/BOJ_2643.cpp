#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

vector<pair<int, int>> v;
int dp[100];

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first <= b.first && a.second <= b.second) {
        return true;
    }
    else {
        return false;
    }
}

int main(void) {
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a < b) {
            swap(a, b);
        }
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end(), compare);

#if 0
    for (int i = 0; i < v.size(); i++) {
        printf("[%d] %d %d\n", i+1, v[i].first, v[i].second);
    }
#endif

    int ans = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < v.size(); i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (compare(v[j], v[i])) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (ans < dp[i]) ans = dp[i];
    }

    printf("%d\n", ans);

    return 0;
}