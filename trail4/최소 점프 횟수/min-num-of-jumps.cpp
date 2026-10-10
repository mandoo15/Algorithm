#include <iostream>
#include <algorithm>
using namespace std;

// 첫 번째 위치로부터 N번째 위치에 도달하기 위해 필요한 최소 점프 횟수
// 점프는 앞으로만 가능, 불가능 하면 -1 출력
// 매 점프마다 1칸 이상 최댓값 이하의 거리를 자유롭게 선택할 수 있다.

int n;
int num[10], ans = 1e9;

void dfs(int level, int cnt) {
    if(level == n-1) {
        ans = min(ans, cnt);
        return;
    }

    for(int i=1; i<=num[level]; i++) {
        cnt += 1;
        dfs(level + i, cnt);
        cnt -= 1;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    dfs(0, 0);

    if(ans == 1e9) {
        cout << -1;
        return 0;
    }
    else {
        cout << ans;
        return 0;
    }

    return 0;
}
