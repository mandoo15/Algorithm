#include <iostream>
#include <string>

using namespace std;

int N, B;

int main() {
    cin >> N >> B;

    string str;
    while(N >= B) {
        int mok = N / B;
        int nam = N % B;

        str += to_string(nam);

        N = mok;
    }

    str += to_string(N);

    for(int i=str.length()-1; i>=0; i--) cout << str[i];
    return 0;
}