#include <iostream>
using namespace std;

int N;
int grid[20][20];

// 연속한 3개의 행과 연속한 3개의 열이 이루는 3*3 크기의 부분 격자를 적절하게 잘 잡아서
// 동전의 개수를 최대로 하는 프로그램

int sum = 0;

void check(int sy, int sx) {
    int ey = sy + 3;
    int ex = sx + 3;
    int cnt = 0;

    if (ey < 0 || ey > N || ex < 0 || ex > N) return;

    for (int i = sy; i < ey; i++) {
        for (int j = sx; j < ex; j++) {
            if (grid[i][j] == 1) cnt++;
        }
    }

    sum = max(sum, cnt);
}

int main() {
    cin >> N;
     
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            check(i, j);
        }
    }

    cout << sum;

    return 0;
}