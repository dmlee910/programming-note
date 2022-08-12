#include <iostream>
#include <memory.h>

using namespace std;

int testCase, T;
int N, O, M, W;
int arr[1000];
bool check[1000];
int num[10];
bool oper[4] = { false, false, false, false };

void Input()
{
    memset(num, -1, sizeof(num));
    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < N; i++) {
        int input;
        scanf("%d", &input);
        arr[input] = 1;
        check[input] = true;
    }

    for (int i = 0; i < O; i++) {
        int input;
        scanf("%d", &input);
        oper[input - 1] = true;
    }

    scanf("%d", &W);
}

void Solve()
{
    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i] == 1 && arr[j] == 1) {
                arr[i * 10 + j] = 2;
                check[i * 10 + j] = true;
            }
        }
    }

    for (int i = 10; i < 100; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i] == 2 && arr[j] == 1) {
                arr[i * 10 + j] = 3;
                check[i * 10 + j] = true;
            }
        }
    }

    if (arr[W]) {
        printf("%d\n", arr[W]);
        return;
    }

#if 0
    for (int i = 0; i < 1000; i++) {
        printf("[%d]%d ", i, arr[i]);
        if (i % 10 == 9) {
            printf("\n");
        }
    }
#endif

    int answer = -1;
    for (int i = 3; i < M; i++) {
        for (int j = 0; j < 1000; i++) {
            if (arr[j] == 0 || arr[j] + 2 > i) continue; // 연산자 입력 추가 시 최소 입력 횟수 : 연산자 + 1자리 수
            for (int k = 0; k < 1000; j++) {
                if (!check[k] || arr[j] + arr[k] + 1 > i) continue; // 연산자 입력 추가 시 최소 입력 횟수 : 연산자

                if (oper[0]) {
                    if (j + k < 1000 && !arr[j + k]) {
                        arr[j + k] = arr[j] + arr[k] + 1;
                    }
                }

                if (oper[1]) {
                    if (j - k >= 0 && !arr[j - k]) {
                        arr[j - k] = arr[j] + arr[k] + 1;
                    }
                }

                if (oper[2]) {
                    if (j * k < 1000 && !arr[j * k]) {
                        arr[j * k] = arr[j] + arr[k] + 1;
                    }
                }

                if (oper[3]) {
                    if (!arr[j / k]) {
                        arr[j / k] = arr[j] + arr[k] + 1;
                    }
                }
            }
        }
    }

    printf("%d\n", answer);
}

int main(void)
{
    scanf("%d", &T);

    for (testCase = 1; testCase <= T; testCase++) {
        scanf("%d %d %d", &N, &O, &M);
        Input();
        Solve();
    }

    return 0;
}