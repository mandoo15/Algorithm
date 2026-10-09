#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, cy = 0, cx = 0;
int a[100][100];
int direct[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // 상하좌우
vector<vector<int>> visit;

void bfs() {
    queue<pair<int, int>> q;
    q.push({cy, cx});
    visit[cy][cx] = 1;

    while(!q.empty()) {
        cy = q.front().first;
        cx = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int ny = cy + direct[i][0];
            int nx = cx + direct[i][1];

            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(visit[ny][nx] == 1) continue;
            if(a[ny][nx] == 0) continue;

            visit[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    visit.assign(n, vector<int>(m, 0));

    bfs();

    if(visit[n-1][m-1] == 1) {
        cout << 1;
        return 0;
    }

    cout << 0;

    return 0;
}
