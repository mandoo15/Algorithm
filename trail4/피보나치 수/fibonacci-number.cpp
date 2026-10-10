#include <iostream>
#include <vector>

using namespace std;

/*
    피보나치 수열 - 이전 두 항의 합이 다음 항이 되는 수열
    N번째 피보나치 수를 구하는 프로그램 작성
*/

int N;
vector<int> arr;

int main() {
    cin >> N;
    arr.assign(N+1, 0);

    arr[1] = 1;
    arr[2] = 1;

    for(int i=3; i<=N; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }

    cout << arr[N];
    

    return 0;
}
