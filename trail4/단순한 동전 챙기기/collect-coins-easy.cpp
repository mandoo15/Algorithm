#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, sy, sx, ey, ex, ans = 1e9, bef = 1e9;
char grid[20][20];
vector<pair<int, int>> order;

/*
    빈 공간 .
    시작점 S
    도착점 E
    최소 3개의 동전 ( 오름차순 ) 수집해 도착점으로 도달하려고 한다.
    꼭 번호가 증가하는 순서대로 수집하고, 상하좌우 인접한 칸 중 하나로 이동하는 것.
    최소 이동 횟수?
*/

int direct[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // 상하좌우

int calc() {
    int by = order[0].first, bx = order[0].second;
    int dist = 0;

    for(int i=1; i<order.size(); i++) {
        int ay = order[i].first, ax = order[i].second;

        dist += abs(by-ay) + abs(bx-ax);

        by = ay;
        bx = ax;
    }

    return dist;
}

void dfs(int level, char bef) {
    if(level == 3) {
        order.push_back({ey, ex});

        int sum = calc();
        ans = min(sum, ans);

        order.pop_back();
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if (grid[i][j] < '1' ||
                grid[i][j] > '9') continue;

            if (bef >= grid[i][j]) continue;

            order.push_back({i, j});

            dfs(level + 1, grid[i][j]);

            order.pop_back();
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];

            if(grid[i][j] == 'S') {
                sy = i;
                sx = j;
            }

            if(grid[i][j] == 'E') {
                ey = i;
                ex = j;
            }
        }
    }

    order.push_back({sy, sx});

    dfs(0, '0');

    if (ans == 1e9) cout << -1;
    else cout << ans;

    return 0;
}
