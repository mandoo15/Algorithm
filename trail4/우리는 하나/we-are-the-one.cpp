#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, k, u, d, ans = 0;
int grid[8][8];
vector<pair<int, int>> city;
vector<vector<int>> visit;
vector<int> counts;
int direct[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // 상하좌우

// K개의 도시를 적절히 골라 갈 수 있는 서로 다른 도시의 수를 최대화하기
// 서로 다른 도시의 수는 탐색 후 visit으로 체크

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    //visit.assign(n, vector<int>(n, 0));
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

            if(ny >= n || nx >= n || ny < 0 || nx < 0) continue;
            if(visit[ny][nx] == 1) continue;

            int dist = abs(grid[cy][cx] - grid[ny][nx]);

            if(dist >= u && dist <= d) {
                visit[ny][nx] = 1;
                q.push({ny, nx});
                cnt++;
            }
        }
    }

    counts.push_back(cnt);
}

int main() {
    cin >> n >> k >> u >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    visit.assign(n, vector<int>(n, 0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {

            if(visit[i][j] == 1) continue;

            bfs(i, j);
        }
    }

    sort(counts.rbegin(), counts.rend());

    for(int i=0; i<min(k, (int)counts.size()); i++) {
        ans += counts[i];
    }  

    cout << ans;

    return 0;
}
