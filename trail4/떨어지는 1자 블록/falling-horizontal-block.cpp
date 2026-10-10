#include <iostream>

using namespace std;

int n, m, k;
int grid[100][100];

// 0 - 빈칸, 1 - 블럭 있음

// 격자판 정보, 떨어질 블럭의 정보가 제공 -> 블럭이 떨어진 이후 상태를 출력

void output() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // k번째 열부터, K+M - 1번째 열의 공간을 차지

    // for(int i=n-1; i>=0; i--) {
    //     int cnt = 0, pos = 0;
    //     for(int j=k-1; j<k+m-1; j++) {
    //         if(grid[i][j] == 0) cnt++;
    //         else break;
    //     }

    //     if(cnt == m) {
    //         for(int j=k-1; j<k+m-1; j++) {
    //             grid[i][j] = 1;
    //         }
    //         output();
    //         return 0;
    //     }
    // } 
    
    for(int i=0; i<n; i++) {
    int cnt = 0;

    for(int j=k-1; j<k+m-1; j++) {
        if(grid[i][j] == 0) cnt++;
        else break;
    }

    if(cnt != m) {
        for(int j=k-1; j<k+m-1; j++) {
            grid[i-1][j] = 1;
        }

        output();
        return 0;
    }
}

// 바닥까지 떨어졌다면
for(int j=k-1; j<k+m-1; j++) {
    grid[n-1][j] = 1;
}

output();

    return 0;
}
