#include <iostream>
#include <memory.h>

using namespace std;

int testCase, T;
int A, B;
int cnt[10];
int delta = 1;

void parse(int num, int d)
{
    while (num > 0) {
        cnt[num % 10] += d;
        num /= 10;
    }
}

void solution(int a, int b)
{
    while (a <= b) {
        for (; a % 10 != 0 && a <= b; a++) {
            parse(a, delta);
        }

        for (; b % 10 != 9 && a <= b; b--) {
            parse(b, delta);
        }

        if (a > b) {
            break;
        }

        a /= 10;
        b /= 10;

        int rowCount = b - a + 1;

        for (int i = 0; i < 10; i++) {
            cnt[i] += rowCount * delta;
        }

        delta *= 10;
    }

    int result = 0;
    for (int i = 1; i < 10; i++) {
        result += i * cnt[i];
    }

    cout << result << endl;
}

int main(void)
{
    cin >> T;

    for (testCase = 1; testCase <= T; testCase++) {
        memset(cnt, 0, sizeof(cnt));

        cin >> A >> B;
        solution(A, B);
    }

    return 0;
}