#include <iostream>
#include <vector>
using namespace std;

int n, m, ans = 0;
// int from[10000], to[10000];
vector<vector<int>> arr;
vector<int> visit;

/*
    양방향 그래프
    1부터 시작 -> 도달할 수 있는 서로 다른 정점의 개수
*/

void dfs(int vertex) {
    for(int curv = 1; curv <=n; curv++) {
        if(arr[vertex][curv] && !visit[curv]) {
            ans++;
            visit[curv] = 1;
            visit[vertex] = 1;
            dfs(curv);
        }
    }

    return;
}

int main() {
    cin >> n >> m;
    arr.assign(n+1, vector<int>(n+1, 0));
    visit.assign(n+1, 0);

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        arr[from][to] = 1;
        arr[to][from] = 1;
    }

    dfs(1);

    cout << ans;

    return 0;
}
