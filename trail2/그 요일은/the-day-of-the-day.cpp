#include <iostream>
#include <string>

using namespace std;

int m1, m2, d1, d2, cnt = 0, start, d;
string A;

int month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 달 ( 1 - 12월 )
string days[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"}; // 요일 ( 월 - 일 )

// A요일은 몇 번 등장하는지 구하기

int main() {
    cin >> m1 >> d1 >> m2 >> d2;
    cin >> A;

    for(int i=0; i<7; i++) {
        if(days[i] == A) {
            d = i;
            break;
        }
    }

    start = d1 + d;

    for(int i=m1; i<m2; i++) {

        int day = month[i];

        while(start <= day) {
            start += 7;
            cnt++;
        }

        start -= day;
    }

    while(start <= d2) {
        start += 7;
        cnt++;
    }


    cout << cnt;

    return 0;
}