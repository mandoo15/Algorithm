#include <iostream>

using namespace std;

int N;
int A[100];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int cnt = 0;

    for(int i=0; i<N; i++) {
        int a = A[i];

        for(int j=i+1; j<N; j++) {
            int b = A[j];
            if(b < a) continue;

            for(int k=j+1; k<N; k++) {
                int c = A[k];

                if(c < b) continue;

                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}