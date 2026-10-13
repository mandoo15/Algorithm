#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    1 ~ M번까지 버호 순서대로 총 M개의 지점이 연결되어 있음
    M이 6인 경우 윷놀이 판의 모습
    1 2 3 4 5 6

    
*/

int n, m, k, ans = 0;
int nums[12];

vector<int> sum;
vector<int> order;

void dfs(int level) {
    if(level == n) {

        int cnt = 0;
        for(int i=0; i<order.size(); i++) {
            int num = order[i];

            sum[num] += nums[i];
        }

        for(int i=0; i<k; i++) {
            if(sum[i] >= m) cnt++;
        }

        ans = max(ans, cnt);

        // 원상복구
        for(int i=0; i<k; i++) {
            sum[i] = 1;
        }
        
        return;
    }

    for(int i=0; i<k; i++) {
        
        order.push_back(i);

        dfs(level + 1);

        order.pop_back();
    }
}

int main() {
    cin >> n >> m >> k;

    sum.assign(k, 1);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    dfs(0);

    cout << ans;

    return 0;
}
