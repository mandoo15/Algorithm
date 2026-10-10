#include <iostream>
#include <vector>

using namespace std;

/*
    정확히 N개의 칸에 색칠을 하여 각 행과 열에 정확히 1개의 색칠된 칸만 오게
    최솟값이 최대가 되로록
*/

int n, ans = 0;
int grid[10][10];
vector<int> visit;
vector<pair<int, int>> path;

void dfs(int level) {
    if(level == n) {
        int sum = 1e9;

        for(int i=0; i<n; i++) {
            int y = path[i].first;
            int x = path[i].second;

            sum = min(sum, grid[y][x]);
        }

        ans = max(sum, ans);
        return;
    }

    for(int i=0; i<n; i++) {
        if(visit[i] == 1) continue;

        path.push_back({level, i});
        visit[i] = 1;

        dfs(level + 1);

        visit[i] = 0;
        path.pop_back();
    }
}
 
int main() {
    cin >> n;
    visit.assign(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    dfs(0);

    cout << ans;

    return 0;
}
