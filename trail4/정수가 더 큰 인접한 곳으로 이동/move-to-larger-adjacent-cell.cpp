#include <iostream>
#include <vector> 

using namespace std;

int n;
int r, c;
int a[101][101];
int direct[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
vector<int> ans;

int check(int y, int x) {
    int cy = y;
    int cx = x;
    int sum = a[cy][cx];
    
    for(int i=0; i<4; i++) {
        int ny = cy + direct[i][0];
        int nx = cx + direct[i][1];

        if(ny > n || nx > n || nx < 1 || ny < 1) continue;

        int nextsum = a[ny][nx];

        if(nextsum > sum) {
            cy = ny;
            cx = nx;
            sum = nextsum;
            break;
        }
    }

    if(sum == a[y][x]) {
        return 1;
    }

    else {
        r = cy;
        c = cx;
        ans.push_back(a[r][c]);
    }

    return 0;
}

int main() {
    cin >> n >> r >> c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    ans.push_back(a[r][c]);

    while(true) {
        int num = check(r, c);
        
        if(num == 1) break;
    }

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}