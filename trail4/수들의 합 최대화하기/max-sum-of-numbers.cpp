#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    2차원 격자 내 정수값이 있음
    정확히 N개의 칸에 색칠하여 각 행과 열에 1개의 색칠된 칸만 오게 한다
    이러한 조건 하에 색칠된 칸에 적힌 수들의 합 중 최댓값
*/


int n, ans = 0;
int grid[10][10];
vector<pair<int, int>> path;
vector<int> visit;

void dfs(int level) {
    if(level == n) {
        int sum = 0;

        for(int i=0; i<n; i++) {
            int y = path[i].first;
            int x = path[i].second;

            //cout << grid[y][x] << " ";

            sum += grid[y][x];
        }

        ans = max(ans, sum);
        return;
    }

    for(int i=0; i<n; i++) {
        if(visit[i] == 1) continue;

        path.push_back({level, i});
        visit[i] = 1;

        dfs(level + 1);

        path.pop_back();
        visit[i] = 0;
    }
} 

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    visit.assign(n, 0);

    dfs(0);
    

    cout << ans;

    return 0;
}
