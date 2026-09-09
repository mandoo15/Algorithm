#include <iostream>
#include <algorithm>

using namespace std;

int n;
int x1, x2;

int minusarr[101] = {0}; // -1 ~ -100
int plusarr[101] = {0}; // 0 ~ 100

// 끝점은 겹치는 것으로 생각 X

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1 >> x2;

        if(x1 < 0) {
            // 1. x1 < 0 && x2 < 0 ---> minus
            if(x2 < 0) {
                for(int j=-1*x2; j<-1*x1; j++) {
                    minusarr[j]++;
                }
            }

            // 2. x1 < 0 && x2 > 0 ---> minus / plus
            if(x2 >= 0) {
                for(int j=1; j<-1*x1; j++) { // minus
                    minusarr[j]++;
                }

                for(int j=0; j<x2; j++) { // plus
                    plusarr[j]++;
                }
            }
        }

        else { // x1이 양수이기 때문에, x2도 무조건 양수
            for(int j=x1; j<x2; j++) { // plus
                plusarr[j]++;
            }
        }
    }


    sort(minusarr, minusarr + 101);
    sort(plusarr, plusarr + 101);

    int minussum = minusarr[100];
    int plussum = plusarr[100];

    cout << max(minussum, plussum);
    

    return 0;
}