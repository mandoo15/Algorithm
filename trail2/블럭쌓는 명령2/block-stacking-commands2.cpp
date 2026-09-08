#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int A[100], B[100];

vector<int> arr;

int main() {
    cin >> N >> K;

    arr.assign(N+1, 0);

    for (int i = 0; i < K; i++) {
        cin >> A[i] >> B[i];

        for(int j=A[i]; j<=B[i]; j++) {
            arr[j]++;
        }
    }


    sort(arr.begin(), arr.end());

    cout << arr[N];



    

    return 0;
}