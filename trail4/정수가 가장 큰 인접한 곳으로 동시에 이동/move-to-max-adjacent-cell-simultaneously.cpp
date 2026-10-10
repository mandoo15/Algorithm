#include <iostream>
#include <vector>

using namespace std;

int n, m, t;
int a[20][20];
int r[400], c[400];
int direct[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
vector<vector<int>> nextcount;
vector<pair<int, int>> ball;

void check(int y, int x) {
    int cy = y, cx = x, sum = 0;
    int dy = 0, dx = 0;

    for(int i=0; i<4; i++) {
        int ny = cy + direct[i][0];
        int nx = cx + direct[i][1];

        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

        int nextsum = a[ny][nx];
        if(sum < nextsum) {
            sum = nextsum;
            dy = ny;
            dx = nx;
        }
    }

    nextcount[dy][dx]++;
}

void inspect() {
    ball.clear();

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(nextcount[i][j] >= 2) {
                nextcount[i][j] = 0;
            }

            if(nextcount[i][j] == 1) {
                ball.push_back({i, j});
            }
        }
    }

    
}

int main() {
    cin >> n >> m >> t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> r[i] >> c[i];
        ball.push_back({r[i]-1, c[i]-1});
    }

    for(int i=0; i<t; i++) {
        nextcount.assign(n, vector<int>(n, 0));
        
        if(ball.size() == 0) {
            cout << 0;
            return 0;
        }

        for(int j=0; j<ball.size(); j++) {
            check(ball[j].first, ball[j].second);
        }

        inspect();
    }

    cout << ball.size();

    return 0;
}
