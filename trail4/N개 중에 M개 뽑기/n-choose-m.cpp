#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> path;

void dfs(int level, int start) {
    if(level == M) {

        for(int i=0; i<M; i++) {
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i=start; i<=N; i++) {
        path.push_back(i);

        dfs(level + 1, i + 1);

        path.pop_back();
    }
}

int main() {
    cin >> N >> M;

    // 1 이상 N 이하 정수 중 M개의 정수를 골라 만들 수 있는 조합
    dfs(0, 1);

    return 0;
}
