#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, cost = 1;
int a[100][100];
int direct[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // 상하좌우
vector<vector<int>> visit;

// 탈출 가능한 경로의 최소 이동횟수
// 뱀이 있는 곳 0, 없는 곳 1

int bfs(int cy, int cx) {
    queue<pair<int, int>> q;
    q.push({cy, cx});
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    visit[cy][cx] = 1;
    dist[cy][cx] = 0;

    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int ny = cy + direct[i][0];
            int nx = cx + direct[i][1];
            int nextcost = dist[cy][cx] + 1;

            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(visit[ny][nx] == 1) continue;

            if(a[ny][nx] == 0) continue;

            if(nextcost < dist[ny][nx]) {
                dist[ny][nx] = nextcost;
                visit[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }

    return dist[n-1][m-1];
}

int main() {
    cin >> n >> m;
    visit.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    int ans = bfs(0, 0);

    if(ans == 1e9) cout << -1;
    else cout << ans;

    return 0;
}
