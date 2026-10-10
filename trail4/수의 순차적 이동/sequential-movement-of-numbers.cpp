#include <iostream>
#include <vector>

using namespace std;

int n, m;
int grid[20][20];
int direct[8][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {1,-1}, {1,1}, {-1,1}};
vector<pair<int, int>> ind;

// direct를 통해 위치에서 인접한 칸들 중 가장 큰 수와 가운데 칸의 수를 교환

// M번의 턴에 걸친 수 이동
// 수 1이 적힌 위치부터 N*N이 적히 위치까지 이동

void check(int y, int x) {
    int cy = y;
    int cx = x;

    int sum = 0, indy = 0, indx = 0;

    for(int i=0; i<8; i++) {
        int ny = cy + direct[i][0];
        int nx = cx + direct[i][1];

        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

        int nextsum = grid[ny][nx];

        if(sum < nextsum) {
            sum = nextsum;
            indy = ny;
            indx = nx;
        }
    }

    swap(grid[y][x], grid[indy][indx]);
}

void change(int num) {
    for(int j=0; j<n; j++) {
        for(int k=0; k<n; k++) {

            if(grid[j][k] == num) {
                check(j, k);
                return;
            }
        }
    }
}
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    for(int turn=0; turn<m; turn++) {
        for(int num=1; num<=n*n; num++) {
            change(num);
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
