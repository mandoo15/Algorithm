#include <iostream>
#include <vector>

using namespace std;

/*
    N층 높이의 계단을 오르기
    한 번에 2계단 또는 3계단으로 올라갈 수 있을 때
    N층 높이의 계단에 올라가기 위한 서로 다른 방법의 수
*/

int n;
vector<int> dp;

int main() {
    cin >> n;
    dp.assign(n+1, 0);

    // dp[n] = dp[n-2] + dp[n-3];

    dp[0] = 1;

    for(int i=0; i<=n; i++) {
        if(i >= 2) {
            dp[i] += dp[i-2];
        }
        if(i >= 3) {
            dp[i] += dp[i-3];
        }

        dp[i] %= 10007;
    }

    cout << dp[n];

    return 0;
}