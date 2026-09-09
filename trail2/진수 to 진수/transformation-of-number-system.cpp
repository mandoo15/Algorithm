#include <iostream>
#include <string>

using namespace std;

int a, b, ans = 0;
string n;

int main() {
    cin >> a >> b;
    cin >> n;

    // 1. a진수의 수 n을 10진수로 변환하기
    int cnt = 0;
    for(int i=n.length()-1; i>=0; i--) { // 뒤에서부터
        int anum = (int)(n[i] - '0');

        int sum = 1;
        for(int j=0; j<cnt; j++) { // 
            sum *= a;
        }
        ans += anum * sum;
        cnt++;
    }

    // 2. 10진수로 변환한 값을 b진수로 변경
    string s;

    while(ans >= b) {
        int mok = ans / b;
        int nam = ans % b;

        s += to_string(nam);
        ans = mok;
    }
    s += to_string(ans);

    for(int i=s.length()-1; i>=0; i--) cout << s[i];

    return 0;
}