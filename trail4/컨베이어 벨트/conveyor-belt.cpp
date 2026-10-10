#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, t;
int u[200];
int d[200];
vector<int> arr;

/*
    시계 방향으로 한 칸씩 회전하는 컨베이어 벨트
    컨베이어 벨트 위아래로 N개씩 2*N개의 정수가 두 줄로 적혀있고
    1초에 한 칸씩 이동
    T초의 시간이 흐른 뒤 컨베이어 벨트에 놓여있는 정수들의 상
*/

int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        cin >> u[i];
        arr.push_back(u[i]);
    }

    for (int i = 0; i < n; i++) {
        cin >> d[i];
        arr.push_back(d[i]);
    }
    int cnt = 0;


    for(int i=0; i<t; i++) {
        int temp = arr[2*n-1];

        for (int j = 2*n-1; j >= 1; j--) {
            arr[j] = arr[j-1];
        }
        //swap(arr[0], arr[2*n-1]);

        arr[0] = temp;
    }

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
        
    for(int i=n; i<2*n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
