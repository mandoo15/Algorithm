#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k, ans = 0;
int grid[100][100];
int r[10000], c[10000];
vector<vector<int>> visit;

int direct[4][2] ={{-1,0}, {1,0}, {0,-1}, {0,1}}; // 상하좌우

void bfs(int y, int x) {
    queue<pair<int,int>> q;

    q.push({y, x});

    visit[y][x] = 1;

    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int ny = cy + direct[i][0];
            int nx = cx + direct[i][1];

            if(nx < 0 || ny < 0 || ny >= n || nx >= n) continue;
            if(visit[ny][nx] == 1) continue;
            if(grid[ny][nx] == 1) continue;

            visit[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
}

int main() {
    cin >> n >> k;

    visit.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++) cin >> r[i] >> c[i];

    for(int i=0; i<k; i++) {
        int y = r[i]-1;
        int x = c[i]-1;

        bfs(y, x);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(visit[i][j] == 1) ans++;
        }
    }
    
    cout << ans;
    

    return 0;
}
