#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ans = 0;
int A[20];
vector<int> path;

// N개의 음이 아닌 정수가 있을 때
// 그 중 M개의 정수를 뽑아 모두 XOR한 결과의 최댓값

void dfs(int level, int start) {
    if(level == m) {
        int sum = path[0];
        for(int i=1; i<m; i++) {
            sum = sum ^ path[i];
        }

        ans = max(ans, sum);
        return;
    }

    for(int i=start; i<n; i++) {
        path.push_back(A[i]);

        dfs(level + 1, i + 1);

        path.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    dfs(0, 0);

    cout << ans;

    return 0;
}