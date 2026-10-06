#include <iostream>
using namespace std;

int n;
int x[100];
char dir[100];

int arr[2001] = {0}; // -1000 ~ 1000

// 정수 좌표 K와 K+1 사이의 길이 1인 구간을 단위로 보고,
// 단위 구간을 2번 이상 지나간 것의 개수가 답

int cur = 1000;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];

        if(dir[i] == 'L') {
            for(int j=0; j<x[i]; j++) {
                cur--;
                arr[cur]++;
            }
        }

        else {
             for(int j=0; j<x[i]; j++) {
                arr[cur]++;
                cur++;
            }
        }

    }

    int ans = 0;

    for(int i=0; i<2001;i++) {
        if(arr[i] >=2) ans++;
    }

    cout << ans;    

    return 0;
}