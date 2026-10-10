#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int r1, c1, r2, c2;
// 대각선 {-1,-1}, {1,-1}, {-1,1}, {1,1};
// 대각선들의 상하좌우?
int direct[8][2] = {{-2,-1}, {-1,-2}, {1,-2}, {2,-1}, {-1,2}, {-2,1}, {1,2}, {2,1}};
vector<vector<int>> visit;
// vector<vector<int>> map;

int bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visit[y][x] = 1;
    vector<vector<int>> dist(n+1, vector<int>(n+1, 1e9));
    dist[y][x] = 0;

    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i=0; i<8; i++) {
            int ny = cy + direct[i][0];
            int nx = cx + direct[i][1];
            int nextcost = dist[cy][cx] + 1;

            if(ny < 1 || nx < 1 || ny > n || nx > n) continue;
            if(visit[ny][nx] == 1) continue;

            if(nextcost < dist[ny][nx]) {
                dist[ny][nx] = nextcost;
                visit[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }

    return dist[r2][c2];
}

int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    // map.assign(n, vector<int>(n, 0));
    visit.assign(n+1, vector<int>(n+1, 0));

    int ans = bfs(r1, c1);

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
