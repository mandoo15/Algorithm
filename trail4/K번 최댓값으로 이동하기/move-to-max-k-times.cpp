#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// N * N 격자
// 상하좌우로만 이동 가능 -> K번 반복 -> 위치 찾기
// 조건
// 1. 시작 위치에서 상하좌우로 이동할 수 있으나 이동 경로 안에 있는 모든 원소값이 X보다 작아야 됨
// 그런 경우에만 이동 가능한 칸
// 2. 이동 가능한 칸 기준에서 가장 큰 값으로 이동
// 3. 2의 값이 여러 개일 경우 행 번호가 가장 작은 곳으로 이동
// 3도 동일하다면 열 번호가 가장 작은 곳으로 이동
// 이것을 K번 반복했을 때 현재 위치?

int N, K, cy, cx, sum = 0, val = 0;
vector<vector<int>> arr;
vector<vector<int>> posvisit;
vector<vector<int>> visit;
int direct[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} }; // 상하좌우

int check() {
    int cnt = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (visit[i][j] == 1) continue;

            if (arr[i][j] == val && posvisit[i][j] == 1) {
                visit[i][j] = 1;
                cy = i;
                cx = j;
                sum = arr[cy][cx];
                return 1;
            }
        }
    }

    if (cnt == 0) return 0;
}

void bfs(int cy, int cx) {
    queue<pair<int, int>> q;
    q.push({ cy, cx });
    val = 0;

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + direct[i][0];
            int nx = cx + direct[i][1];

            if (ny > N || ny < 1 || nx < 1 || nx > N) continue;
            if (posvisit[ny][nx] == 1) continue;
            if (visit[ny][nx] == 1) continue;

            if (arr[ny][nx] < sum) {
                posvisit[ny][nx] = 1;
                val = max(arr[ny][nx], val);
                q.push({ ny, nx });
            }
        }
    }
}

int main() {
    cin >> N >> K;
    arr.assign(N+1, vector<int>(N+1, 0));
    visit.assign(N+1, vector<int>(N+1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> cy >> cx;
    sum = arr[cy][cx];

    for (int i = 0; i < K; i++) {
        posvisit.assign(N+1, vector<int>(N+1, 0)); // 가능한 위치 저장
        bfs(cy, cx); // 탐색과정
        int n = check();
        if (n == 0) {
            break;
        }
    }

    cout << cy << " " << cx;
    
    return 0;
}