#include <iostream>
#include <string>

using namespace std;

string A;

int main() {
    cin >> A;

    int len = A.length();

    int ans = 0;

    for(int i=0; i<A.length(); i++) {

        char x = A[i];
        if(x == ')') continue;

        for(int j=i+1; j<A.length(); j++) {
            char y = A[j];

            if(y == ')') ans++;
        }
    }

    cout << ans;

    return 0;
}