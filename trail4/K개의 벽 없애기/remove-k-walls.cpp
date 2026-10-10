#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, ans = 1e9;
int grid[100][100];
int r1, c1, r2, c2;
int direct[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // 상하좌우
vector<pair<int, int>> wall;
vector<vector<int>> visit;

// K개의 벽을 적절히 없애 도착점까지의 최소 도달시간
// 0 - 이동 가능, 1 - 이동 불가능

int bfs(int y, int x) {
    visit.assign(n, vector<int>(n, 0));
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    queue<pair<int, int>> q;

    q.push({y, x});
    dist[y][x] = 0;
    visit[y][x] = 1;

    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int ny = cy + direct[i][0];
            int nx = cx + direct[i][1];
            int nextcost = dist[cy][cx] + 1;

            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(visit[ny][nx] == 1) continue;
            if(grid[ny][nx] == 1) continue;

            if(nextcost < dist[ny][nx]) {
                dist[ny][nx] = nextcost;
                visit[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }

    return dist[r2][c2];
}

void dfs(int level, int start) {

    if(level == k) {
        int sum = bfs(r1, c1);
        ans = min(ans, sum);
    }

    for(int i=start; i<wall.size(); i++) {
        int y = wall[i].first;
        int x = wall[i].second;

        grid[y][x] = 0;
        dfs(level + 1, i + 1);
        grid[y][x] = 1;
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if(grid[i][j] == 1) {
                wall.push_back({i, j});
            }
        }
    }

    cin >> r1 >> c1; // 시작점
    cin >> r2 >> c2; // 도착점

    r1--;
    c1--;
    r2--;
    c2--;
    
    dfs(0, 0);

    if(ans == 1e9) {
        cout << -1;
        return 0;
    }
    else {
        cout << ans;
        return 0;
    }

    return 0;
}
