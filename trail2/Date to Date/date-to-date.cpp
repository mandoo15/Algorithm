#include <iostream>

using namespace std;

int m1, d1, m2, d2;
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    cin >> m1 >> d1 >> m2 >> d2;

    if(m1 == m2) {
        cout << d2 - d1 + 1;
        return 0;
    }

    int sum = month[m1] - d1;

    if(m1 + 1 < m2) {
        for(int i=m1+1; i<m2; i++) {
            sum += month[i];
        }
    }

    sum += d2;

    cout << sum + 1;

    return 0;
}