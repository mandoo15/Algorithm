
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans = 0, sum = 0;
int grid[100][100];
int direct[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

int cnt = 0;
vector<vector<int>> visit;

void dfs(int cy, int cx, int num) {
    visit[cy][cx] = 1;
    cnt++;

    for(int i=0; i<4; i++) {
        int ny = cy + direct[i][0];
        int nx = cx + direct[i][1];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n)
            continue;

        if(visit[ny][nx] == 1) continue;
        if(grid[ny][nx] != num) continue;

        dfs(ny, nx, num);
    }
}

int main() {
    cin >> n;

    visit.assign(n, vector<int>(n, 0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {

            if(visit[i][j] == 1) continue;

            cnt = 0;
            dfs(i, j, grid[i][j]);

            if(cnt >= 4) sum++;

            ans = max(ans, cnt);
        }
    }

    cout << sum << " " << ans;

    return 0;
}
