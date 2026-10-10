#include <iostream>
#include <vector>

using namespace std;

/*
    1 - N까지의 수를 정확히 한 번씩만 사용해
    만들 수 있는 가능한 모든 수열
    사전 순으로 가장 뒤에 있는 수열부터 출력
*/

int n;
vector<int> path;
vector<int> visit;

void dfs(int level) {
    if(level == n) {
        for(int i=0; i<n; i++) {
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i=n; i>=1; i--) {

        if(visit[i] == 1) continue;

        path.push_back(i);
        visit[i] = 1;

        dfs(level + 1);

        visit[i] = 0;
        path.pop_back();
    }
}

int main() {
    cin >> n;
    visit.assign(n+1, 0);

    dfs(0);

    return 0;
}
