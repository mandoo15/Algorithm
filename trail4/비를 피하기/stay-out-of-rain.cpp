#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, h, m, ey = 0, ex = 0;
int grid[100][100];
int direct[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // 상하좌우
vector<vector<int>> dist;
queue<pair<int, int>> q;

// 각 사람마다 비를 피할 수 있는 공간까지의 최단거리

/*
    정수 0 - 이동 가능
    정수 1 - 이동 불가능
    정수 2 - 사람이 있음
    정수 3 - 비를 피할 수 있는 공간
*/

void bfs() {
    
    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int ny = cy + direct[i][0];
            int nx = cx + direct[i][1];

            if(ny >= n || nx >= n || nx < 0 || ny < 0) continue;
            if(dist[ny][nx] != -1) continue;
            if(grid[ny][nx] == 1) continue;

            dist[ny][nx] = dist[cy][cx] + 1;
            q.push({ny, nx});
        }
    }
    
}

int main() {
    cin >> n >> h >> m;
    dist.assign(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = -1;

            cin >> grid[i][j];

            if(grid[i][j] == 3) {
                q.push({i, j});
                dist[i][j] = 0;
                // 다중 BFS
                // 비를 피할 수 있는 공간 저장
            }
        }
    }

    bfs();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2)
                cout << dist[i][j] << " ";
            else
                cout << 0 << " ";
        }
        cout << '\n';
    }

    

    return 0;
}
