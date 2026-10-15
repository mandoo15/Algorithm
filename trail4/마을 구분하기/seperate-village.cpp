#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, sy, sx, cnt = 1;
int grid[25][25];
int visit[25][25] = {0};

int direct[4][2]  = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

// N X N 크기의 이차원 영역에 사람 혹은 벽이 놓여 있다. 상하좌우 인접한 영역에 있는 사람들은 같은 마을에 있는 것으로 간주.
// 사람과 벽이 배치되어 있는 경우, 그림 안의 점선과 같이 마을을 나눌 수 있다. 총 마을의 개수와 같은 마을에 있는 사람의 수를 오름차순 정렬

vector<int> order;
int ans = 0;

void check() {
    int count = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {

            if(visit[i][j] == 1) count++; 
        }
    }

    order.push_back(count);
    ans++;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {

            if(visit[i][j] == 1) visit[i][j] = 0; 
        }
    }
}

void dfs(int cy, int cx) {

    visit[cy][cx] = 1;
    cnt++;

    for(int i=0; i<4; i++) {
        int ny = cy + direct[i][0];
        int nx = cx + direct[i][1];

        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

        if(grid[ny][nx] == 0) continue;
        if(visit[ny][nx] == 1) continue;

        dfs(ny, nx);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if(grid[i][j] == 1) {
                sy = i;
                sx = j;
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {

            if(grid[i][j] == 0) continue;
            if(visit[i][j] == 1) continue;

            cnt = 0;

            dfs(i, j);

            order.push_back(cnt);
            ans++;
        }
    }

    sort(order.begin(), order.end());

    cout << ans << endl;
    for(int i=0; i<order.size(); i++) {
        cout << order[i] << endl;
    }

    
    return 0;
}
