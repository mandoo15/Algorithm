#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// N * N 격자
// 격자 내 기울어진 직사각형
// 기울어진 직사각형 - 격자 내 한 지점으로부터 대각선으로 움직이며
// 반시계 순회를 했을 때 지나왔던 지점들의 집합

// 아래에서 시작해서 1, 2, 3, 4번 방향순으로 순회해야 하며 각 방향으로 최소 1번 움직여야 함
// 이동 중 격자 밖으로 넘어가서는 안됨

// 가능한 기울어진 직사각형들 중 최대의 합을 출력하라

int n, ans = 0;
int grid[20][20];

int direct[4][2] = { {-1,-1}, {1,-1}, {1,1}, {-1,1} }; // 대각선 상하좌우

void check(int sy, int sx, int a, int b) {

    int cy = sy;
    int cx = sx;

    int sum = grid[cy][cx];

    // 각 방향으로 이동해야 하는 횟수
    int moveCnt[4] = { a, b, a, b };

    for (int dir = 0; dir < 4; dir++) {

        for (int i = 0; i < moveCnt[dir]; i++) {

            cy += direct[dir][0];
            cx += direct[dir][1];

            // 격자 밖으로 나가면 실패
            if (cy < 0 || cy >= n || cx < 0 || cx >= n)
                return;

            // 마지막 이동은 시작점으로 돌아오는 것
            if (cy == sy && cx == sx)
                continue;

            sum += grid[cy][cx];
        }
    }

    // 정확히 시작점으로 돌아왔다면 직사각형 완성
    if (cy == sy && cx == sx) {
        ans = max(ans, sum);
    }
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            // 1번 방향 이동 횟수
            for (int a = 1; a < n; a++) {

                // 2번 방향 이동 횟수
                for (int b = 1; b < n; b++) {

                    check(i, j, a, b);
                }
            }

        }
    }

    cout << ans;

    return 0;
}