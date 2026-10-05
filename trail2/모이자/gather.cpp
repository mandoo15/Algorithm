#include <iostream>
#include <algorithm>

using namespace std;

int n;
int A[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int answer = 1e9;

    for(int i=0; i<n; i++) {

        int sum = 0;

        for(int j=0; j<n; j++) {
            int dist = abs(j - i);
            sum += A[j] * dist;
        }

        answer = min(answer, sum);
    }

    cout << answer;

    return 0;
}