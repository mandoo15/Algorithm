#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;
int grid[100][100];
int direct[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // 상하좌우
vector<vector<int>> dist;
vector<vector<int>> visit;
queue<pair<int, int>> q;

/*
    // 모든 상한 귤로부터 상하좌우 인접한 곳에 있는 귤이 전부 상하게 될 때
    // 최초로 상하게 되는 시간 ( 최소 시간 )

    0 - 해당 칸에 아무것도 없음
    1 - 해당 칸에 귤이 놓여있음
    2 - 해당 칸에 상한 귤이 처음부터 놓여있음
*/

void bfs() {
    
    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int ny = cy + direct[i][0];
            int nx = cx + direct[i][1];
            int nextcost = dist[cy][cx] + 1;

            if(ny >= n || nx >= n || ny < 0 || nx < 0) continue;
            if(visit[ny][nx] == 1) continue;
            if (grid[ny][nx] == 0) continue;

            dist[ny][nx] = nextcost;
            visit[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
}

int main() {
    cin >> n >> k;
    dist.assign(n, vector<int>(n, -2)); 
    visit.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 2) {
                q.push({i, j});
                dist[i][j] = 0;
                visit[i][j] = 1;
            }
        }
    }

    bfs();

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] == 0) {
                cout << -1 << " ";
            }

            else {
                cout << dist[i][j] << " ";
            }
        } 
        cout << endl;
    }

    return 0;
}
