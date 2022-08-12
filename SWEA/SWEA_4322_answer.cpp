#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
 
int t, n, tc;
int a[1001], b[1001];
unsigned char c[1001][11][11][11][11][11];
int ti[5];
 
 
bool dp(int x, int cnt) {
    if (x == n)
        return true;
    int ch[5] = { 0, };
    for (int i = 0; i < cnt; ++i)
        ch[i] = a[x] > ti[i] ? 0 : ti[i] - a[x];
 
    if (c[x][ch[0]][ch[1]][ch[2]][ch[3]][ch[4]] == tc * 5 + cnt) return false;
 
    c[x][ch[0]][ch[1]][ch[2]][ch[3]][ch[4]] = tc * 5 + cnt;
    for (int i = 0; i < cnt; ++i) {
        if (ti[i] - a[x] + b[x] > 10) continue;
        int temp = ti[i];
        ti[i] = a[x] > ti[i] ? a[x] + b[x] : ti[i] + b[x];
        if (dp(x + 1, cnt)) {
            ti[i] = temp;
            return true;
        }
        ti[i] = temp;
    }
    return false;
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    for (tc = 1; tc <= t; ++tc) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i] >> b[i];
 
        int f = 1, i = 1;
        cout << "#" << tc << " ";
 
        for (; i <= 5; ++i) {
            if (dp(0, i)) {
                f = 0;
                break;
            }
        }
        cout << (f ? -1 : i) << '\n';
    }
    return 0;
}