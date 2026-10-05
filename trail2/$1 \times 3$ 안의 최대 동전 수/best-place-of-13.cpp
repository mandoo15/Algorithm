#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[20][20];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> arr[i][j];
    
    int maxsum = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N-2; j++) {
            maxsum = max(maxsum, arr[i][j] + arr[i][j+1] + arr[i][j+2]);
        }
    }

    cout << maxsum;

    return 0;
}