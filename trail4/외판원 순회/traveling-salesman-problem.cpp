#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans = 10000000;
int A[11][11];

/*
    1번 지점에서 출발해 모든 지점을 정확히 딱 한 번씩만 방문하고 다시 1번 지점으로 돌아오려고 한다.
    i번 지점에서 j번 지점으로 이동하는데 드는 비용 A가 주어졌을 때 모든 정점을 겹치지 않게 방문하고 되돌아오는데 필요한 최소 비용
*/

vector<int> path;
vector<int> visit;

void dfs(int level) {
    if(level == n) {
        int sum = 0, y = 1, ny = 0;

        for(int i=0; i<path.size(); i++) {
            ny = path[i];

            if(A[y][ny] == 0) return;

            sum += A[y][ny];

            y = ny;
        }
        if(A[y][1] == 0) return;
        
        sum += A[y][1];

        ans = min(ans, sum);

        return;
    }

    for(int i=2; i<=n; i++) {

        if(visit[i] == 1) continue;

        path.push_back(i);
        visit[i] = 1;

        dfs(level + 1);

        path.pop_back();
        visit[i] = 0;
    }
}

int main() {
    cin >> n;
    visit.assign(n+1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    dfs(1);

    cout << ans;

    return 0;
}
