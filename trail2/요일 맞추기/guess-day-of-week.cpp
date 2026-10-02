#include <iostream>
using namespace std;

int m1, d1, m2, d2;

int month[13] = {
    0, 31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31
};

string days[7] = {
    "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"
};

int main() {
    cin >> m1 >> d1 >> m2 >> d2;

    int date1 = 0;
    int date2 = 0;

    
    for (int i = 1; i < m1; i++) {
        date1 += month[i];
    }
    date1 += d1;

    
    for (int i = 1; i < m2; i++) {
        date2 += month[i];
    }
    date2 += d2;

    
    int daysum = date2 - date1;

    
    int index = (daysum % 7 + 7) % 7;

    cout << days[index];

    return 0;
}