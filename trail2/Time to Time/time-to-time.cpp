#include <iostream>

using namespace std;

int a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;

    c -= 1;
    d += 60;

    d -= b;
    c -= a;

    int ans = d + c * 60;

    cout << ans;



    return 0;
}