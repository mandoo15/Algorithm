#include <iostream>
#include <string>

using namespace std;

string unlock_code;
char wire_color;
int seconds;

struct info {
    string s;
    char x;
    int n;
};

int main() {
    cin >> unlock_code >> wire_color >> seconds;

    info k;
    k.s = unlock_code;
    k.x = wire_color;
    k.n = seconds;

    cout << "code : " << k.s << endl;
    cout << "color : " << k.x << endl;
    cout << "second : " << k.n << endl;

    return 0;
}