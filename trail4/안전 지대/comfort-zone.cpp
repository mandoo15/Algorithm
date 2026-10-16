#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> height(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> height[i][j];
        }
    }

    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};

    int answerK = 1;
    int maxSafeZones = -1;

    for (int k = 1; k <= 100; k++) {
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int safeZones = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] || height[i][j] <= k)
                    continue;

                safeZones++;

                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                            continue;

                        if (visited[nx][ny] || height[nx][ny] <= k)
                            continue;

                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }

        // 같은 개수라면 더 작은 k를 유지해야 하므로
        // strictly greater일 때만 갱신한다.
        if (safeZones > maxSafeZones) {
            maxSafeZones = safeZones;
            answerK = k;
        }
    }

    cout << answerK << ' ' << maxSafeZones;
    return 0;
}