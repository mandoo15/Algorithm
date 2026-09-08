#include <iostream>
#include <string>

using namespace std;

int a, b, c;

int main() {
    cin >> a >> b >> c;

    int sum = a * b * c;

    string str = to_string(sum);

    int ans = 0;

    for(int i=0; i<str.length(); i++) {
        ans += (int)(str[i] - '0');
    }

    cout << ans;

    return 0;
}