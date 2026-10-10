#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    좌표 평면 위 점 N개, 점 M개를 적절히 선택해 
    선택한 점들 중 거리가 가장 먼 두 점 사이의 거리값이 최소가 되도록 하는 프로그램
*/

/*
    선택한 점들 중 거리가 가장 먼 두 점이라면
    가장 작은 점, 가장 큰 점의 차가 가장 작도록
*/

int n, m, ans = 1e9;
int x[20], y[20];
vector<pair<int, int>> dist;

vector<pair<int, int>> dots;

void dfs(int level, int start) {
    if(level == m) {
        int sum = 0;

        for(int i=0; i<dist.size(); i++) {
            int y = dist[i].first, x = dist[i].second;

            for(int j=i+1; j<dist.size(); j++) {
                int y2 = dist[j].first, x2 = dist[j].second;

                int d = (y-y2)*(y-y2) + (x-x2)*(x-x2);
                sum = max(sum, d);
            }
        }

        ans = min(sum, ans);
        return;
    }

    for(int i=start; i<dots.size(); i++) {

        dist.push_back({dots[i].first, dots[i].second});

        dfs(level + 1, i + 1);

        dist.pop_back();

    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        dots.push_back({x[i], y[i]});
    }

    dfs(0, 0);

    cout << ans;

    return 0;
}
