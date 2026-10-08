#include <iostream>
#include <vector>
using namespace std;

/*
    N * M 크기의 배열
    우측 하단까지 뱀에게 물리지 않고 탈출하려고 한다.

    이동 시에는 반드시 아래, 오른쪽 중 인접한 방향으로 이동할 수 있으며
    뱀이 있는 칸으로는 이동을 할 수 없다.

    뱀에게 물리지 않고 탈출 가능한 경로가 있는지를 판별하는 코드를 작성

    좌측 상단에서 출발, 우측 하단까지
*/

int n, m;
int grid[100][100];

int direct[2][2] = {{1,0}, {0,1}}; // 하, 우
vector<vector<int>> memo;
/*
  -1 아직 탐색하지 않음 -> dfs 탐색
  0 해당 좌표에서 목적지까지 갈 수 없음 -> 탐색하지 않고 0 반환
  1 해당 좌표에서 목적지까지 갈 수 있음 -> 탐색하지 않고 1 반환 
*/

int ey, ex;

int dfs(int y, int x) {

    if(memo[y][x] != -1) return memo[y][x];

    if (y == ey && x == ex) {
        return memo[y][x] = 1;
    }

    for(int i=0; i<2; i++) {
        int cy = y + direct[i][0];
        int cx = x + direct[i][1];

        if(cy < 0 || cy >= n || cx < 0 || cx >= m) continue;

        if(grid[cy][cx] == 0) continue;

        if(dfs(cy, cx)) {
            return memo[y][x] = 1;
        }
    }

    return memo[y][x] = 0;
}

int main() {
    cin >> n >> m;
    ey = n-1, ex = m-1;
    memo.assign(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            // 뱀이 없는 경우 1, 있는 경우 0
        }
    }

    if (grid[0][0] == 0) {
        cout << 0;
    }
    else {
        cout << dfs(0, 0);
    }
    

    return 0;
}
