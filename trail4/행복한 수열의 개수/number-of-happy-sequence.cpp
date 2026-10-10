#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int grid[100][100];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int row = 1, col = 1;
        int maxRow = 1, maxCol = 1;

        for (int j = 1; j < n; j++) {

            // 세로 방향 검사
            if (grid[j][i] == grid[j-1][i])
                row++;
            else
                row = 1;

            // 가로 방향 검사
            if (grid[i][j] == grid[i][j-1])
                col++;
            else
                col = 1;

            maxRow = max(maxRow, row);
            maxCol = max(maxCol, col);
        }

        if (maxRow >= m)
            ans++;

        if (maxCol >= m)
            ans++;
    }

    cout << ans;

    return 0;
}