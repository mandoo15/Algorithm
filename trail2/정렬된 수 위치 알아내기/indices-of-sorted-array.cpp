#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

int N;
int num;

vector<tuple<int, int>> arr;
// 원소값, 원래 위치

vector<int> array;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num; // 원소값 입력
        
        arr.push_back({num, i});
    }

    //원소값 기준 오름차순, 값이 같으면 원래 위치 기준 오름차숨
    sort(arr.begin(), arr.end());

    vector<int> answer(N);

    for(int i=0; i<N; i++) {
        int value, origin;

        tie(value, origin) = arr[i];
        
        answer[origin] = i+1;
    }

    for(int i=0; i<N; i++) {
        cout << answer[i] << " ";
    }

 
    return 0;
}
