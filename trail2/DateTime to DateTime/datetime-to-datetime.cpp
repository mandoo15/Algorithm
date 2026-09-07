#include <iostream>

using namespace std;

int a, b, c;

int main() {
    cin >> a >> b >> c;

    if(a < 11 ) {
        cout << -1;
        return 0;
    }

    if(a == 11 && b < 11 || a == 11 && b == 11 && c < 11) {
        cout << -1;
        return 0;
    }

    int curmin = c + b*60 + a*24*60;
    int befmin = 11 + 11*60 + 11*24*60;

    cout << curmin - befmin;
    return 0;
}