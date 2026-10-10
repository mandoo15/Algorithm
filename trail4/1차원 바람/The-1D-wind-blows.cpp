#include <iostream>
#include <algorithm>

using namespace std;

int n, m, q;
int a[100][100];

void check(int col, char d, int dir);
void move(int col, char d);

void move(int col, char d) {

    if(d == 'L') {
        int temp = a[col][m-1];

        for(int i=m-1; i>=1; i--) {
            a[col][i] = a[col][i-1];
        }

        a[col][0] = temp;
    }

    if(d == 'R') {
        int temp = a[col][0];

        for(int i=1; i<m; i++) {
            a[col][i-1] = a[col][i];
        }

        a[col][m-1] = temp;
    }
}

void check(int col, char d, int dir) {

    int next = col + dir;

    if (next < 0 || next >= n)
        return;

    bool flag = false;

    for (int i = 0; i < m; i++) {
        if (a[next][i] == a[col][i]) {
            flag = true;
            break;
        }
    }

    if (!flag)
        return;

    char nextD = (d == 'L') ? 'R' : 'L';

    move(next, nextD);
    check(next, nextD, dir);
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int r; // 행
        char d;
        cin >> r >> d;

        r--;

        move(r, d);

        check(r, d, -1);
        check(r, d, 1);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    

    return 0;
}
