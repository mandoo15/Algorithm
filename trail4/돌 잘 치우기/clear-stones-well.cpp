#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, m, ans = 0;
int grid[100][100];
int r[10000], c[10000];
int direct[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // 상하좌우
vector<vector<int>> visit;
vector<pair<int, int>> stone;


// 1 - 돌이 있는 곳, 0 - 길

int bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visit[y][x] = 1;
    int cnt = 1;

    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int ny = cy + direct[i][0];
            int nx = cx + direct[i][1];

            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(grid[ny][nx] == 1) continue;
            if(visit[ny][nx] == 1) continue;

            visit[ny][nx] = 1;
            cnt++;
            q.push({ny, nx});
        }
    }

    return cnt;
}

void dfs(int level, int start) {
    if(level == m) {
        visit.assign(n, vector<int>(n, 0));

        int sum = 0;

        for(int i=0; i<k; i++) {
            if(visit[r[i]][c[i]]) continue;

            sum += bfs(r[i], c[i]);
        }

        ans = max(ans, sum);
        return;
    }

    for(int i=start; i<(int)stone.size(); i++) {
        int y = stone[i].first;
        int x = stone[i].second;

        grid[y][x] = 0;
        dfs(level + 1, i + 1);
        grid[y][x] = 1;
    }
}

int main() {
    cin >> n >> k >> m;
    visit.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 1) {
                stone.push_back({i, j});
            }
        }

    visit.assign(n, vector<int>(n, 0));

    for (int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
    }

    dfs(0, 0);

    cout << ans;

    

    return 0;
}
