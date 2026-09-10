#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[10];

int check(int level, int sum) {
    if(level == n) {
        return sum;
    }

    int num = sum;
    int cur = arr[level];

    int ans = 1;

    for(int i=2; i<=sum; i++) {

        while (num % i == 0 && cur % i == 0) {
            ans *= i;

            num /= i;
            cur /= i;
        }
    }

    ans *= num * cur;

    return check(level + 1, ans);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n); // 오름차순 정렬

    cout << check(1, arr[0]);

    return 0;
}