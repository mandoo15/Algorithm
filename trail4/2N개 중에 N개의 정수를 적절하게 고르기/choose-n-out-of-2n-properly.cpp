#include <iostream>
#include <vector>

using namespace std;

int n, ans = 1e9;
int num[20];

/*
    2N개의 정수로 이루어진 수열 A가 주어졌을 때, 주어진 수를 각각 N개씩 2개의 그룹으로 나눠 각 그룹 원소합의 차가 최소가 되도록 하는 프로그램
*/

vector<int> order;
vector<int> visit;

void dfs(int level, int start) {
    if(level == n) {
        int s1 = 0, s2 =0;

        for(int i=0; i<order.size(); i++) {
            s1 += num[order[i]];
        }

        for(int i=0; i<visit.size(); i++) {
            if(visit[i] == 1) continue;

            s2 += num[i];
        }

        ans = min(ans, abs(s1-s2));
        return;
    }

    for(int i=start; i<2*n; i++) {
        if(visit[i] == 1) continue;

        visit[i] = 1;
        order.push_back(i);

        dfs(level + 1, i + 1);

        order.pop_back();
        visit[i] = 0;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
    }

    visit.assign(2*n, 0);
    
    dfs(0, 0);

    cout << ans;

    return 0;
}
