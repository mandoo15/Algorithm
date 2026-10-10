#include <iostream>
#include <vector>

using namespace std;

int K, N;
vector<int> path;

void check(int level) {
    if(level == N) {
        int num = path[0], cnt = 0;

        for(int i=0; i<path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i=1; i<=K; i++) {

        // 직전 2개가 현재 숫자와 같으면 선택하지 않음
        if(level >= 2 &&
           path[level-1] == i &&
           path[level-2] == i) {
            continue;
        }

        path.push_back(i);
        check(level+1);
        path.pop_back();
    }
}

int main() {
    cin >> K >> N;

    check(0);

    return 0;
}
