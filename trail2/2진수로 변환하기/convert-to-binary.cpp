#include <iostream>

using namespace std;

int n;
string str;

int main() {
    cin >> n;

    while(n >= 2) {
        int mok = n / 2;
        int nam = n % 2;

        str += to_string(nam);
        n = mok;
    }

    str += to_string(n%2);

    for(int i=str.length()-1; i>=0; i--) {
        cout << str[i];
    }

    return 0;
}