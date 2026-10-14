#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, ans = 0;

// 4가지 연산을 사용해 연산의 횟수를 최소화하여 1을 만들어

/*
    1. 현재 수에서 1을 뺌
    2. 현재 수에서 1을 더함
    3. 현재 수가 2로 나누어 떨어질 경우, 현재 수를 2으로 나눔
    4. 현재 수가 3으로 나누어 떨어질 경우, 현재 수를 3으로 나눔
*/

int bfs(int num) {
    queue<int> q;
    vector<int> dist(num+2, -1);

    q.push(num);
    dist[num] = 0;

    while(!q.empty()) {
        int cnum = q.front();
        q.pop();

        if (cnum == 1) {
            return dist[cnum];
        }

        for(int i=0; i<4; i++) {
            int nnum;

            if (i == 0) {
                nnum = cnum - 1;
            }
            else if (i == 1) {
                nnum = cnum + 1;
            }
            else if (i == 2) {
                if (cnum % 2 != 0) continue;
                nnum = cnum / 2;
            }
            else {
                if (cnum % 3 != 0) continue;
                nnum = cnum / 3;
            }

            if(nnum < 1 || nnum > num + 1) continue;

            if (dist[nnum] != -1) continue;

            dist[nnum] = dist[cnum] + 1;
            q.push(nnum);
        }
    }

    return 0;
}


int main() {
    cin >> N;

    cout << bfs(N);

    return 0;
}
